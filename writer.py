
import parser
from parser import * 

def get_leaf_name(le: Leaf) -> str:
    if type(le) is Leaf:
        return 'Leaf_' + str(le.unique_id)
    if type(le) is Argument:
        return 'Argument_' + str(le.unique_id)
    if type(le) is Lambda:
        return 'Lambda_' + str(le.unique_id)
    if type(le) is Bind:
        return 'Bind_' + str(le.name)
    raise Exception('Unknown type {}'.format(type(le)))
def get_member_name(leaf_name: str) -> str:
    return 'm_' + leaf_name
def get_ovv_member_name(mem: Leaf):
    name = get_leaf_name(mem)
    name = get_member_name(name)
    t = type(mem)
    if t is Bind or t is Lambda:
        return '(&{})'.format(name)
    else:
        raise Exception('expected types {} and {} '.format(Bind, Argument, Lambda))

def get_argument_by_parents(me: Lambda, arg: Argument):
    re = 'this->'
    p = me
    while p.arg != arg:
        if p is None: raise Exception('Argument not found (None parent)')
        p = p.parent
        re += 'parent->'
        while not type(p) is Lambda:
            if p is None: raise Exception('Argument not found (None parent)')
            p = p.parent
            re += 'parent->'
    return re + 'x'

def get_return_part(le: Leaf, base_lambda: Lambda) -> str:
    exec_line = ''
    for l in le.leafs:
        t = type(l)
        if t is Bind or t is Lambda:
            name = get_ovv_member_name(l)
            if exec_line:
                exec_line += '->eval({})'.format(name)
            else:
                exec_line += name
        elif t is Argument:
            name = get_argument_by_parents(base_lambda, l)
            if exec_line:
                exec_line += '->eval({})'.format(name)
            else:
                exec_line += name
        elif t is Leaf:
            part = get_return_part(l, base_lambda)
            if exec_line:
                exec_line += '->eval({})'.format(part)
            else:
                exec_line += part
        else:
            raise Exception('unexpected type {}'.format(t))
    return '(' + exec_line + ')'
def get_ovv(le: Leaf) -> list:
    exec_line = get_return_part(le, le)
    exec_line = 'return ' + exec_line + ';'
    yield exec_line

def get_lambda_members(le: Lambda) -> iter:
    for l in le.leafs:
        t = type(l)
        if t is Lambda:
            yield l
        if t is Bind:
            yield l
        if t is Leaf:
            for le2 in get_lambda_members(le=l):
                yield le2
def get_unique_lambda_members(le: Lambda) -> list:
    re = []
    for m in get_lambda_members(le=le):
        if not m in re:
            re.append(m)
    return re
def write_named_lambda(file, le: Lambda, lambda_name: str):
    for l in le.leafs:
        if type(l) is Lambda:
            write_lambda(file=file, le=l)

    file.write('der({}) {{\n'.format(lambda_name))

    is_bind = le.parent is None
    constructor = '\t{}({}) : fun({})'.format(lambda_name, '' if is_bind else 'ff p', 'nullptr' if is_bind else 'p')

    members = get_unique_lambda_members(le=le)
    for l in members:
        if type(l) is Lambda:
            name = get_leaf_name(l)
            name_m = get_member_name(name)
            
            file.write('\t{} {};\n'.format(name, name_m))
            constructor += ', {}(this)'.format(name_m)
        elif type(l) is Bind:
            name = get_leaf_name(l)
            name_m = get_member_name(name)

            file.write('\t{} {};\n'.format(name, name_m))
        else:
            raise Exception('Unexpected member type {}'.format(type(l)))

    constructor += ' {}\n\n'
    file.write(constructor)

    file.write('\tovv {')
    for line in get_ovv(le):
        file.write('\n\t\t' + line)
    file.write('\n\t}\n')
    file.write('};\n')
def write_lambda(file, le: Leaf):
    name = get_leaf_name(le)
    return write_named_lambda(file=file, le=le, lambda_name=name)

def write(file, le: Leaf):
    if type(le) is Lambda:
        return write_lambda(file, le)
    elif type(le) is Bind:
        name = get_leaf_name(le)
        return write_named_lambda(file=file, le=le.target, lambda_name=name)
    else:
        raise Exception('Dont know how to start writing from {} type'.format(type(le)))
def write_some(filepath: str, binds: list):
    file = open(filepath, 'w')
    with open('template.cc', 'r') as r:
        template = r.read()
        file.write(template)

    proper_binds = []
    exec_expr = []
    expr_count = 0
    for b in binds:
        if b.name is None:
            b.name = 'EXPR_' + str(expr_count)
            expr_count += 1
            exec_expr.append(b)
        else:
            proper_binds.append(b)
            
    for b in proper_binds:
        write(file=file, le=b)
    for e in exec_expr:
        write_named_lambda(file=file, le=e.target, lambda_name=e.name)
    
    file.write('int main() {\n')
    file.write('\tputs("start");\n')
    for e in exec_expr:
        file.write('\t' + e.name + '{}.eval(&debug_id_instance)->eval(&error_not_lambda_instance); \n')
    file.write('\tputs("end");\n')
    file.write('\treturn 0; \n}')

    file.close()
    print('write some ended')

def main():
    # expr = r'\b -> b x y'
    # expr = r'\a b -> x a'
    expr = r'\a b c -> x (a b) c'
    # expr = r'\a b -> b'

    p = parse_tokens(expr)
    p = parse_structure(p, [], [Bind('x', Leaf([], None))], None)
    # t = p.print(0)
    # print(t)

    file = open('test.cc', 'w')
    write(file, p)
    file.close()
    print('end writing')

if __name__ == '__main__':
    main()
