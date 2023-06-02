fin = open("bcount.in", 'r')
fout = open("bcount.out", 'w')
N, M = map(int, fin.readline().split(" "))
past = [(0, 0, 0)]
a, b, c = 0, 0, 0
for i in range(N): 
    num = int(fin.readline())
    if(num == 1): a += 1
    elif(num == 2): b += 1
    else: c += 1
    past.append((a, b, c))
for i in range(M):
    s, e = map(int, fin.readline().split(" "))
    sa, sb, sc = past[s - 1]
    ea, eb, ec = past[e]
    fout.write(str(ea - sa) + " " + str(eb - sb) + " " + str(ec - sc) + "\n")