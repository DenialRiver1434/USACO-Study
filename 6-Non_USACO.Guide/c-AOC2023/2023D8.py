from math import gcd
fin = open("lineup.in", 'r')
logtext = fin.read().splitlines()
if (len(logtext) == 0):
    logtext = input().splitlines()

dest = {}

ins = logtext[0]

starts = []
for line in logtext[2:]:
    parts = line.split(" = ")
    dest[parts[0]] = parts[1][1:-1].split(', ')
    if (parts[0][-1] == 'A'):
        starts.append(parts[0])

c = 1
for s in starts:
    tc = 0
    pos = s
    while (pos[-1] != "Z"):
        if (ins[tc % len(ins)] == 'L'):
            pos = dest[pos][0]
        else:
            pos = dest[pos][1]
        tc += 1
    c = (c * tc) // gcd(c, tc)

print(c) # Part a