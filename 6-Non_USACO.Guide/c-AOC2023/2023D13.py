fin = open("lineup.in", 'r')
logtext = fin.read().splitlines()
if (len(logtext) == 0):
    logtext = input().splitlines()

tc = 0

def ans (e1):
    global grid

    vgrid = []
    for i in range(len(grid[0])):
        s = ""
        for j in range(len(grid)):
            s += grid[j][i]
        vgrid.append(s)
    

    for vsplit in range(1, len(grid[0])):
        dist = min(vsplit, len(grid[0]) - vsplit)
        up = []
        for i in range(vsplit - 1, vsplit - 1 - dist, -1):
            up.append(vgrid[i])
        down = []
        for i in range(vsplit, vsplit + dist):
            down.append(vgrid[i])
        if (up == down):
            if (vsplit != e1):
                return vsplit
        
    for vsplit in range(1, len(grid)):
        dist = min(vsplit, len(grid) - vsplit)
        up = []
        for i in range(vsplit - 1, vsplit - 1 - dist, -1):
            up.append(grid[i])
        down = []
        for i in range(vsplit, vsplit + dist):
            down.append(grid[i])
        if (up == down):
            if (vsplit * 100 != e1):
                return vsplit * 100
    return -1

def process ():
    global grid
    norm = ans (-1)

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if (grid[i][j] == '#'):
                grid[i] = grid[i][:j] + '.' + grid[i][j+1:]
            else:
                grid[i] = grid[i][:j] + '#' + grid[i][j+1:]

            nnorm = ans(norm)
            if (nnorm != -1):
                return nnorm
                
            if (grid[i][j] == '#'):
                grid[i] = grid[i][:j] + '.' + grid[i][j+1:]
            else:
                grid[i] = grid[i][:j] + '#' + grid[i][j+1:]

grid = []
for line in logtext:
    if (len(line) == 0):
        tc += process()
        grid.clear()
    else:
        grid.append(line)
tc += process()


print(tc)