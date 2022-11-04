N = int(input())
line = [int(n) for n in input().split(" ")]
c = 0
prefix = [0]
for l in line:
    c = (c + l) % N
    prefix.append(c)
tc = 0
impo = {}
for p in prefix:
    if(p in impo): tc += impo[p]
    if(p not in impo): impo[p] = 1
    else: impo[p] += 1
print(tc)