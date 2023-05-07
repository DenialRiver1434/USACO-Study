fin = open("lifeguards.in", 'r')
fout = open("lifeguards.out", 'w')

N = int(fin.readline())
points = []
starts = {}
ends = {}
for i in range(N):
    a, b = map(int, fin.readline().split(" "))
    starts[a] = i
    ends[b] = i
    points.append(a)
    points.append(b)

solotime = [0 for i in range(N)]
totaltime = 0
points.sort()
active = set()
for i in range(N * 2):
    p = points[i]
    if(p in starts): active.add(starts[p])
    if(p in ends): active.remove(ends[p])
    if(len(active) >= 1): totaltime += points[i + 1] - points[i]
    if(len(active) == 1):
        solocow = list(active)[0]
        solotime[solocow] += points[i + 1] - points[i]
fout.write(str(totaltime - min(solotime)))
fin.close()
fout.close()