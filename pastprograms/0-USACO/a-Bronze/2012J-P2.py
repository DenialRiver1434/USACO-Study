N, K = map(int, input().split(" "))
starts = {}
ends = {}
for i in range(K):
    s, e = map(int, input().split(" "))
    if(s - 1 not in starts): starts[s - 1] = 1
    else: starts[s - 1] += 1
    if(e not in ends): ends[e] = 1
    else: ends[e] += 1

bales = []
layer = 0
for i in range(N):
    if(i in starts): layer += starts[i]
    if(i in ends): layer -= ends[i]
    bales.append(layer)
bales.sort()
print(bales[N // 2])