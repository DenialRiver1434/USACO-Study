import sys
sys.setrecursionlimit(100000)
def dfs(tile, boot):
    global boots
    global snow
    global possible
    global past
    global N
    global B
    if(tile >= N - 1): 
        possible = min(possible, boot)
        return
    if(boot >= B): return
    level, maxsnow, maxstep = snow[tile], boots[boot][0], boots[boot][1]
    if(maxsnow < level): return
    if((tile, boot) in past): return
    else: past.add((tile, boot))
    for i in range(tile + maxstep, tile, -1): 
        if(i >= N): 
            dfs(i, boot)
            return
        elif(snow[i] <= maxsnow):
            dfs(i, boot)
    for i in range(boot + 1, B): 
        if(snow[i] <= boots[i][0]): dfs(tile, i)

fin = open("snowboots.in", 'r')
fout = open("snowboots.out", 'w')
N, B = map(int, fin.readline().split(" "))
snow = fin.readline().split(" ")
boots = []
past = set()
for i in range(N): 
    snow[i] = int(snow[i])
for i in range(B): 
    depth, speed = map(int, fin.readline().split(" "))
    boots.append([depth, speed])
possible = B
dfs(0, 0)
fout.write(str(possible))
fin.close()
fout.close()