fin = open("loan.in", 'r')

def check(pair):
    if(pair[0] == (M - 1)): return False
    if(grid[pair[0] + 1][pair[1]]): return False
    return True

def checkleft(pair):
    if(grid[pair[0]][pair[1] - 1]): return False
    return True
    
def checkright(pair):
    if(grid[pair[0]][pair[1] + 1]): return False
    return True

def move (dir):
    if(dir == '>'):
        if(a[1] != 6 and b[1] != 6 and c[1] != 6 and d[1] != 6 and e[1] != 6):
            if(checkright(a) and checkright(b) and checkright(c) and checkright(d) and checkright(e)):
                a[1] += 1
                b[1] += 1
                c[1] += 1
                d[1] += 1
                e[1] += 1
    elif(dir == '<'):
        if(a[1] != 0 and b[1] != 0 and c[1] != 0 and d[1] != 0 and e[1] != 0):
            if(checkleft(a) and checkleft(b) and checkleft(c) and checkleft(d) and checkleft(e)):
                a[1] -= 1
                b[1] -= 1
                c[1] -= 1
                d[1] -= 1
                e[1] -= 1
    else:
        if(check(a) and check(b) and check(c) and check(d) and check(e)):
            a[0] += 1
            b[0] += 1
            c[0] += 1
            d[0] += 1
            e[0] += 1
            return True
        return False
    return True

N, M = map(int, fin.readline().split(" "))
order = fin.readline()
mod = len(order)

grid = [[0 for i in range(7)] for i in range(M)]
past = [0]
a = []; b = []; c = []; d = []; e = []
co = 0

highest = M
for i in range(151 * N + 1):
    if((i % 5) == 0):
        a = [highest - 4, 2]
        b = [highest - 4, 3]
        c = [highest - 4, 4]
        d = [highest - 4, 5]
        e = [highest - 4, 5]
    elif((i % 5) == 1):
        a = [highest - 5, 2]
        b = [highest - 6, 3]
        c = [highest - 5, 3]
        d = [highest - 4, 3]
        e = [highest - 5, 4]
    elif((i % 5) == 2):
        a = [highest - 6, 4]
        b = [highest - 5, 4]
        c = [highest - 4, 4]
        d = [highest - 4, 3]
        e = [highest - 4, 2]
    elif((i % 5) == 3):
        a = [highest - 7, 2]
        b = [highest - 6, 2]
        c = [highest - 5, 2]
        d = [highest - 4, 2]
        e = [highest - 4, 2]
    else:
        a = [highest - 4, 2]
        b = [highest - 4, 3]
        c = [highest - 5, 2]
        d = [highest - 5, 3]
        e = [highest - 5, 3]
    while (True):
        move(order[co % mod])
        co += 1
        if(not move("dir")):
            grid[a[0]][a[1]] = 1
            grid[b[0]][b[1]] = 1
            grid[c[0]][c[1]] = 1
            grid[d[0]][d[1]] = 1
            grid[e[0]][e[1]] = 1
            highest = min([highest, a[0], b[0], c[0], d[0], e[0]])
            past.append(M - highest)
            break

for i in range(151):
    print(past[i * 2022 + 1498])