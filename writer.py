
import parser
from parser import * 

def get_leaf_name(le: Leaf, base: Leaf) -> str:
    if type(le) is Leaf:
        return 'Leaf_' + str(le.unique_id)
    if type(le) is Argument:
        return 'Argument_' + str(le.unique_id)
    if type(le) is Lambda:
        return 'Lambda_' + str(le.unique_id)
    if type(le) is Bind:
        return 'Bind_' + str(le.unique_id)
    return 'kek'
def get_member_name(leaf_name: str) -> str:
    return leaf_name + '_m'
def if_return(le: Leaf, base: Leaf) -> bool:
    for l in le.leafs:
        t = type(l)
        if t is Bind or t is Argument:
            return True
    return False
def get_ovv_member_name(mem: Leaf, le: Leaf):
    name = get_leaf_name(mem, le)
    name = get_member_name(name)
    if type(mem) is Bind:
        return '(&{})'.format(name)
    if type(mem) is Argument:
        return name

    raise Exception('expected types {} and {} '.format(Bind, Argument))
def get_ovv(le: Leaf, base: Leaf) -> list:
    if if_return(le, base):
        first_name = get_ovv_member_name(mem=le.leafs[0], le=le)
        exec_line = '{}'.format(first_name)
        
        for l in le.leafs[1:]:
            t = type(l)
            if t is Bind or t is Argument:
                name = get_ovv_member_name(mem=l, le=le)
                exec_line += '->eval({})'.format(name)
        exec_line = 'return ' + exec_line + ';'
        yield exec_line

def write_lambda(file, le: Leaf, base: Leaf):
    name = get_leaf_name(le, base)
    file.write('der({}) {{\n'.format(name))

    for l in le.leafs:
        if type(l) is Bind:
            name = get_leaf_name(l, le)
            name_m = get_member_name(name)
            file.write('\t{} {};\n'.format(name, name_m))
        elif type(l) is Argument:
            name = get_leaf_name(l, le)
            name_m = get_member_name(name)
            file.write('\t{} * {};\n'.format(name, name_m))
    # for s in le.scope:

    
    file.write('\tovv(x) {')
    for line in get_ovv(le, base):
        file.write('\n\t\t' + line)
    file.write('\n\t}\n')
    file.write('};\n')

    for l in le.leafs:
        write(file, l, le)
def write_bind(file, le: Leaf, base: Leaf):
    name = get_leaf_name(le, base)
    file.write("// bind {} to be done\n\n".format(name))
def write(file, le: Leaf, base: Leaf):
    if type(le) is Lambda:
        return write_lambda(file, le, base)
    if type(le) is Bind:
        return write_bind(file, le, base)
    # else not writing

expr = r'\b -> b x y'

p = parse_tokens(expr)
p = parse_structure(p, [], [Bind('x', Leaf([])), Bind('y', Leaf([])), Bind('z', Leaf([]))])
# t = p.print(0)
# print(t)

file = open('test.cc', 'w')
write(file, p, None)
file.close()

