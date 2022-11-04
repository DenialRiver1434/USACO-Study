fin = open("rental.in", 'r')
fout = open("rental.out", 'w')

N, B, R = map(int, fin.readline().split(" "))
cows = sorted([int(fin.readline()) for i in range(N)], reverse=True)
info = [[10000000000000, 0]]
for i in range(B):
    space, cost = map(int, fin.readline().split(" "))
    info.append([space, cost])
info.sort(key=lambda x:-x[1])
rent = sorted(([int(fin.readline()) for i in range(R)] + [0 for i in range(max(0, N - R))]))

base = sum(rent)
best = base
for c in cows:
    base -= rent.pop(0)
    while(info[0][0] < c):
        base += info[0][0] * info[0][1]
        c -= info[0][0]
        info.pop(0)
    base += c * info[0][1]
    info[0][0] -= c
    best = max(best, base)

fout.write(str(best))
fin.close()
fout.close()