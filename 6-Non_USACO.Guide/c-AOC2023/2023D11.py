fin = open("lineup.in", 'r')
logtext = fin.read().splitlines()
if (len(logtext) == 0):
    logtext = input().splitlines()


grid = []
adderx = []
addery = []
c = 0
i = 0
for line in logtext:
    grid.append(line)
    if (line.count('#') == 0):
        adderx.append(i)
    i += 1
N = len(grid); M = len(grid[0])
    
for j in range(M):
    c = 0
    for i in range(N):
        c += grid[i][j] == '#'
    if (c == 0):
        addery.append(j)

prefx = [0 for i in range(N)]
prefy = [0 for i in range(M)]
for i in range(N):
    if (i in adderx):
        prefx[i] += 1
    if (i > 0):
        prefx[i] += prefx[i - 1]
for i in range(M):
    if (i in addery):
        prefy[i] += 1
    if (i > 0):
        prefy[i] += prefy[i - 1]

positions = []    
for i in range(N):
    for j in range(M):
        if (grid[i][j] == '#'):
            positions.append((i, j))

tc1 = 0; tc2 = 0
for i in range(len(positions)):
    for j in range(i + 1, len(positions)):
        x1, x2 = positions[i]
        p1, p2 = positions[j]
        tc1 += abs(p1 - x1) + abs(p2 - x2)
        tc2 += abs(p1 - x1) + abs(p2 - x2)
        tc1 += abs(prefx[x1] - prefx[p1]) + abs(prefy[x2] - prefy[p2])
        tc2 += 999999 * (abs(prefx[x1] - prefx[p1]) + abs(prefy[x2] - prefy[p2]))
print(tc1)
print(tc2)