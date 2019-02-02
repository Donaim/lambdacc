
import parser
from parser import *

def split_binding_and_def(line: str) -> (str, str):
    (pre, mid, post) = line.partition('=')

    post = post.strip()
    if mid:
        if not post:
            raise SyntaxError('Binding at line "{}" cannot have empty definition'.format(line))
        
        pre = pre.strip()
        if not pre:
            raise SyntaxError('Binding at line "{}" cannot have empty name'.format(line))
        if any(map(lambda c: c.isspace(), pre)) or parser.LAMBDA_SYMBOL in pre or '\\' in pre:
            raise SyntaxError('Binding "{}" has invalid symbols in its name'.format(pre))
    else:
        post = line.strip()
        pre = None
    return (pre, post)
    
def join_lines(lines: iter) -> iter:
    prev = ''
    for o in lines:
        if  o.startswith('\t') or o.startswith('    '):
            prev += o
        else:
            prev = prev.strip()
            if prev: yield prev
            prev = o
    prev = prev.strip()
    if prev: yield prev

def filter_lines(lines: iter) -> iter:
    for o in lines:
        if len(o) < 1 or o.isspace():
            continue
        if '#' in o:
            (pre, _, post) = o.partition('#')
            if len(post) < 1:
                yield o
            else:
                yield pre
        else:
            yield o

def parse_text(text: str) -> list:
    lines = text.split('\n')
    lines = list(filter_lines(lines))
    lines = list(join_lines(lines))
    tuples = map(lambda o: split_binding_and_def(o), lines)
    toks = map(lambda p: (p[0], parse_tokens(p[1])), tuples)

    binds = []
    for (name, br) in toks:
        s = parse_structure( b=br, scope=[], binds=binds, parent=None )
        binds.append( Bind( name=name, target=s ) )

    return binds

def main():
    print('macro parser loaded :)')

    text = ''
    with open('note.txt', 'r') as r:
        text = r.read()
    binds = parse_text(text)
    for o in binds:
        print('{}=\n{}\n\n'.format(o.name, o.target.print(0)))
    
    import writer
    writer.write_some('generated.cc', binds)

if __name__ == '__main__':
    main()


