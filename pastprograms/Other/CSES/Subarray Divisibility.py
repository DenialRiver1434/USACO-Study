N, target = map(int, input().split(" "))
line = [int(n) for n in input().split(" ")]
c = 0
prefix1 = [0]
for l in line:
    c += l
    prefix1.append(c)
tc = 0
impo = {}
for p in prefix1:
    if(p in impo): tc += impo[p]
    if((p + target) not in impo): impo[p + target] = 1
    else: impo[p + target] += 1
print(tc)