fin = open("paintbarn.in", 'r')
fout = open("paintbarn.out", 'w')

N, target = map(int, fin.readline().split(" "))
change = [[0 for i in range(1001)] for i in range(1001)]
for k in range(N): 
    a, b, c, d = map(int, fin.readline().split(" "))
    for i in range(a, c): change[i][b] += 1; change[i][d] -= 1
count = 0
for i in range(1000):
    for j in range(1000):
        if(change[i][j] == target): count += 1
        change[i][j + 1] += change[i][j]
fout.write(str(count))