
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
    return leaf_name + '_m'
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
    
def get_ovv(le: Leaf) -> list:
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
            name = get_argument_by_parents(le, l)
            if exec_line:
                exec_line += '->eval({})'.format(name)
            else:
                exec_line += name
        else:
            raise Exception('unexpected type {}'.format(t))
    exec_line = 'return ' + exec_line + ';'
    yield exec_line

def write_lambda(file, le: Leaf):
    for l in le.leafs:
        if type(l) is Lambda:
            write_lambda(file=file, le=l)

    name = get_leaf_name(le)
    file.write('der({}) {{\n'.format(name))
    
    constructor = '\t{}(ff p) : fun(p)'.format(name)
    
    for l in le.leafs:
        if type(l) is Lambda or type(l) is Bind:
            name = get_leaf_name(l)
            name_m = get_member_name(name)
            file.write('\t{} {};\n'.format(name, name_m))
            constructor += ', {}(this)'.format(name_m)
    
    constructor += ' {}\n\n'
    file.write(constructor)

    file.write('\tovv {')
    for line in get_ovv(le):
        file.write('\n\t\t' + line)
    file.write('\n\t}\n')
    file.write('};\n')

def write_bind(file, le: Leaf):
    name = get_leaf_name(le)
    file.write("// bind {} to be done\n\n".format(name))
def write(file, le: Leaf):
    if type(le) is Lambda:
        return write_lambda(file, le)
    if type(le) is Bind:
        return write_bind(file, le)
    # else not writing

# expr = r'\b -> b x y'
expr = r'\a b -> x a'
# expr = r'\a b -> b'

p = parse_tokens(expr)
p = parse_structure(p, [], [Bind('x', Leaf([], None), None)], None)
# t = p.print(0)
# print(t)

file = open('test.cc', 'w')
write(file, p)
file.close()

