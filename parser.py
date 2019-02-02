
LAMBDA_SYMBOL = '->'

def find_first_char(s: str, chars: list):
    for i, c in enumerate(s):
        for k in chars:
            if c == k:
                return i
    return -1
def find_first_sub(s: str, subs: list, start: int = 0):
    for i in range(len(s)):
        if i < start: continue
        for k in subs:
            if s.startswith(k, i):
                return i
    return -1
def find_next_bracket(s: str):
    count = 0
    for i, c in enumerate(s):
        if c == '(': count += 1
        elif c == ')':
            count -= 1
            if count == 0:
                return i
    return -count

class Branch:
    def __init__(self, text: str, branches: list, is_lambda: bool, is_token: bool, is_arg: bool):
        self.text = text
        self.branches = branches
        self.is_lambda = is_lambda
        self.is_token = is_token
        self.is_arg = is_arg
    
    @staticmethod
    def from_text(expr: str):
        expr = expr.strip()
        # print('branch="{}"'.format(expr))

        is_lambda = expr[0] == '\\'

        re = Branch(None, [], is_lambda=is_lambda, is_token=False, is_arg=False)

        if is_lambda:
            stop = find_first_sub(expr, [' ', LAMBDA_SYMBOL], start=1)
            if stop < 0:
                raise Exception('Lambda expression "{}" has no body!'.format(expr))
            argname = expr[1:stop]
            re.branches.append( Branch(argname, [], is_lambda=False, is_token=True, is_arg=True) )
            expr = expr[stop:]
        
        while len(expr) > 0:
            if expr[0].isspace():   # skip
                expr = expr[1:]
                continue
            elif expr.startswith(LAMBDA_SYMBOL):     # skip
                expr = expr[len(LAMBDA_SYMBOL):]
                continue
            elif expr[0] == '\\':     # lambda
                re.branches.append(Branch.from_text(expr))
                expr = ''
            elif expr[0] == '(':    # another branch
                stop = find_next_bracket(expr)
                if stop < 0:
                    raise Exception('Wrong number of brackets: need {} more ")"!'.format(stop))
                body = expr[1:stop]
                re.branches.append(Branch.from_text(body))
                expr = expr[stop + 1:]
            else: # simple token
                stop = find_first_char(expr, [' ', '(', '\\'])
                if stop < 0:
                    stop = len(expr)
                tok = expr[0:stop]
                re.branches.append(Branch(tok, [], is_lambda=False, is_token=True, is_arg=False))
                expr = expr[stop:]
        return re

counter = 0
class Leaf:
    def __init__(self, leafs: list, parent):
        self.leafs = leafs
        self.parent = parent
        
        global counter
        self.unique_id = counter
        counter += 1
        
    def print(self, indent: int):
        i_str = '\t' * indent
        l_str = '\n'.join(map ( lambda l: l.print(indent + 1), self.leafs))
        return l_str
    def __eq__(self, other) -> bool:
        return self.unique_id == other.unique_id
    def __ne__(self, other) -> bool:
        return not self == other

class Lambda(Leaf):
    def __init__(self, scope: list, arg, leafs: list, parent: Leaf):
        super(Lambda, self).__init__(leafs, parent=parent)
        self.scope = scope
        self.arg = arg
    def print(self, indent: int):
        i_str = '\t' * indent
        l_str = ''
        for l in self.leafs:
            l_str += '\n' + l.print(indent + 1)
        return '{}(lambda {} of {}): {}'.format(i_str, self.scope, self.arg.name, l_str)

class Argument(Leaf):
    def __init__(self, name: str, parent: Leaf):
        super(Argument, self).__init__([], parent=parent)
        self.name = name
    def __repr__(self):
        return self.print(0)
    def print(self, indent):
        return ('\t' * indent) + '[' + self.name + ']'

class Bind(Leaf):
    def __init__(self, name: str, target: Leaf):
        super(Bind, self).__init__([], parent=None)
        self.name = name
        self.target = target
        self.predefined = False
    def __repr__(self):
        return self.print(0)
    def print(self, indent):
        return ('\t' * indent) + '{' + self.name + '}'


def trimSpaces(s: str) -> str:
    re = ''
    last = ''
    for c in s:
        if c.isspace():
            if last == c:
                continue
            elif last == '\\':
                last = c
                continue
            else:
                re += ' '
        else:
            re += c
        last = c
    return re
def transformMultipleLambdas(s: str) -> str:
    re = ''
    last_lambda = False
    buff = ''
    for i, c in enumerate(s):
        if last_lambda:
            buff += c
            if s.endswith(LAMBDA_SYMBOL, 0, i + 1):
                buff = buff[:-(len(LAMBDA_SYMBOL))].strip()
                buff = buff.replace(' ', ' {} \\'.format(LAMBDA_SYMBOL)) + ' '
                re += buff + LAMBDA_SYMBOL
                
                buff = ''
                last_lambda = False
        else:
            if c == '\\':
                last_lambda = True
            re += c
    return re

def parse_tokens(expr: str) -> Branch:
    expr = trimSpaces(expr)
    expr = transformMultipleLambdas(expr)
    return Branch.from_text(expr)
def parse_token(token: Branch, scope: list, binds: list) -> Leaf:
    if token.text.startswith('$'):
        name = token.text[1:]
        re = Bind(name, None)
        re.predefined = True
        return re
    for arg in scope:
        if arg.name == token.text:
            return arg
    for b in binds:
        if b.name == token.text:
            return b
    raise Exception('not defined binding "{}" in scope = {} and bindings = {}'.format(token.text, scope, list(map(lambda b: b.name, binds))))

def add_scope_argument(current_scope: list, new_arg: Branch, parent: Leaf) -> list:
    for arg in current_scope:
        if arg.name == new_arg.text:
            return current_scope
    return current_scope + [Argument(new_arg.text, parent=parent)]

def parse_leafs(b: Branch, scope: list, binds: list, parent: Leaf) -> list:
    lfs = []
    for t in b.branches:
        if t.is_token:
            if t.is_arg: continue
            lfs.append(parse_token(token=t, scope=scope, binds=binds))
        else:
            lfs.append(parse_structure(t, scope, binds, parent=parent))
    return lfs
def parse_structure(b: Branch, scope: list, binds: list, parent: Leaf) -> Leaf:
    if b.is_lambda:
        arg = b.branches[0]
        sc = add_scope_argument(scope, arg, parent=parent)
        arg = sc[-1]
        re = Lambda(arg=arg, scope=sc, leafs=None, parent=parent)
        lfs = parse_leafs(b=b, scope=sc, binds=binds, parent=re)
        re.leafs = lfs
        return re
    else: # is brackets
        re = Leaf(leafs=None, parent=parent)
        lfs = parse_leafs(b=b, scope=scope, binds=binds, parent=re)
        re.leafs = lfs
        return re

def main():
    # expr = r'   \    a -> \    b ->    (\x    ->    b hello)    a  '
    # expr = r'   \    a b ->    (\x    ->    b hello)    a  '
    expr = r'\n f x -> n(\g h -> h (g f h)) (\u -> x) (\u ->u)'
    # expr = r'\n f x . n(\g h . h (g f h)) (\u . x) (\u .u)'
    # expr = r'\n f x.n(\g h.h(g f h))(\u.x)(\u.u)'
    # expr = r'x y z\k -> y z x'
    # expr = r'\f -> (\x -> x x)(\x -> f(x x))'
    # expr = r'\x->x y'
    # expr = r'\a b -> a'
    # expr = r'\b -> b x y'

    expr = trimSpaces(expr)
    print(expr)
    expr = transformMultipleLambdas(expr)
    print(expr)

    p = parse_tokens(expr)
    p = parse_structure(p, [], [Bind('x', Leaf([], None), None)], None)
    t = p.print(0)
    print(t)
if __name__ == '__main__':
    main()
