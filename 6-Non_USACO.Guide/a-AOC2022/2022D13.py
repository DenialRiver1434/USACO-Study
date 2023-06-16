import functools

def read (inp):
    out = []
    parts = []
    num = ""
    layer = 0
    for p in inp:
        if(p == '['): layer += 1
        elif(p == ']'): layer -= 1
        if(layer == 0 and p == ','):
            parts.append(num)
            num = ""
        else:
            num += p
    if(len(num)): parts.append(num)
    for p in parts:
        if(p.isnumeric()): out.append(int(p))
        else:
            out.append(read(p[1:-1]))
    return out


def compare(left, right):
    if((not isinstance(left, list)) and (not isinstance(right, list))):
        if(left < right): return -2
        elif(left == right): return 0
        else: return 2
    if(not isinstance(left, list)): left = [left]
    if(not isinstance(right, list)): right = [right]

    for i in range(min(len(left), len(right))):
        comp = compare(left[i], right[i])
        if(comp == 0): continue
        if(comp == 2): return 2
        if(comp == -2): return -2
    if(len(left) == len(right)): return 0
    elif(len(left) > len(right)): return 2
    else: return -2

print(compare([], [[]]))

lists = []
N = int(input())
c = 0
for i in range(N):
    left = read(input()[1:-1])
    right = read(input()[1:-1])
    lists.append(left)
    lists.append(right)
    input()

lists = sorted(lists, key=functools.cmp_to_key(compare))

a = 0; b = 0
for i in range(len(lists)):
    if(lists[i] == [[2]]):
        a = i + 1
    elif(lists[i] == [[6]]):
        b = i + 1
print(a * b)