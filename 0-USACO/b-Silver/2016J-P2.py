fin = open("div7.in", 'r')
fout = open("div7.out", 'w') 
N = int(fin.readline())
best = 0
prev = {0:-1}
past = [0]
for i in range(N):
    new = (past[-1] + int(fin.readline())) % 7
    if(new in prev): best = max(best, i - prev[new])
    else: prev[new] = i
    past.append(new)
fout.write(str(best))