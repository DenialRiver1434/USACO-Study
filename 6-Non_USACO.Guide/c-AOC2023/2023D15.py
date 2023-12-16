pos = {}
boxes = [[] for i in range(256)]

def hsh (s):
    t = 0
    for ch in s:
        t += ord(ch)
        t *= 17
        t %= 256
    return t

def remove (s, ps):
    global pos
    global boxes
    for i in range(10):
        if ((s, i) in boxes[ps]):
            boxes[ps].remove((s, i))
    pos.pop(s)

fin = open("lineup.in", 'r')
logtext = fin.read().split(",")

tc = 0
for l in logtext:
    if ('-' in l):
        partes = l.split('-')
        if (partes[0] in pos):
            loc = pos[partes[0]]
            remove(partes[0], loc)
    else:
        partes = l.split('=')
        if (partes[0] in pos):
            loc = pos[partes[0]]
            for i in range(10):
                if ((partes[0], i) in boxes[loc]):
                    boxes[loc][boxes[loc].index((partes[0], i))] = (partes[0], int(partes[1]))
        else:
            loc = hsh(partes[0])
            pos[partes[0]] = loc
            boxes[loc].append((partes[0], int(partes[1])))
            
for i in range(256):
    for j in range(len(boxes[i])):
        a, b = boxes[i][j]
        tc += (i + 1) * (j + 1) * b

print(tc)