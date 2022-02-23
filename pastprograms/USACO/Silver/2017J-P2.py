fin = open("hps.in", 'r')
fout = open("hps.out", 'w') 
N = int(fin.readline())
past = [(0, 0, 0)]
a, b, c = 0, 0, 0
best = 0
for i in range(N):
    read = fin.readline()[:-1]
    if(read == "P"): a += 1
    elif(read == "H"): b += 1
    else: c += 1
    past.append((a, b, c))
total = [a, b, c]

#P and then H
for cp, ch, cs in past: best = max(best, (total[1] - ch + cp))
#H and then P
for cp, ch, cs in past: best = max(best, (total[0] - cp + ch))
#P and then S
for cp, ch, cs in past: best = max(best, (total[2] - cs + cp))
#S and then P
for cp, ch, cs in past: best = max(best, (total[0] - cp + cs))
#S and then H
for cp, ch, cs in past: best = max(best, (total[1] - ch + cs))
#H and then S
for cp, ch, cs in past: best = max(best, (total[2] - cs + ch))

fout.write(str(best))