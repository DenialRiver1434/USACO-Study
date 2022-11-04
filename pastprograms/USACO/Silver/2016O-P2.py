fin = open("diamond.in", 'r')
fout = open("diamond.out", 'w')

N, K = map(int, fin.readline().split(" "))
sizes = sorted([int(fin.readline()) for i in range(N)])
ends = []
right = 0
for i in range(N):
    while(right < N):
        if(sizes[right] - sizes[i] > K): break
        right += 1
    ends.append(right - i)
taken = []
maxto = [0]
for e in ends[::-1]: maxto.insert(0, max(maxto[0], e))
best = 0
for i in range(N):
    current = ends[i]
    best = max(best, current + maxto[min(N, i + current)])
fout.write(str(best))