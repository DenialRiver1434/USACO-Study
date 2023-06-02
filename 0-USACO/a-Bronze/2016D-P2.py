fin = open("blocks.in", 'r')
fout = open("blocks.out", 'w')
def chartoint(ch): return ord(ch) - 97
total = [0 for i in range(26)]
N = int(fin.readline())
for i in range(N):
    a, b = map(str, fin.readline().split(" "))
    c1, c2 = [0 for i in range(26)], [0 for i in range(26)]
    if("\n" in b): b = b[:-1]
    for ch in a: c1[chartoint(ch)] += 1
    for ch in b: c2[chartoint(ch)] += 1
    for i in range(26): total[i] += max(c1[i], c2[i])
for t in total: fout.write(str(t) + '\n')
fin.close()
fout.close()