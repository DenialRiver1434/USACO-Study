N = int(input())
grid = [[0 for i in range(200)] for i in range(400)]
my = 0
for i in range(N):
    line = input()
    parts = line.split(" -> ")
    px, py = map(int, parts[0].split(","))
    my = max(py, my)
    px -= 300 # 450 - 550, 0 - 200
    for p in parts[1:]:
        x, y = map(int, p.split(","))
        my = max(y, my)
        x -= 300
        if(x == px and y < py):
            for i in range(y, py + 1):
                grid[x][i] = 1
        elif(x == px):
            for i in range(y, py - 1, -1):
                grid[x][i] = 1
        elif(x < px):
            for i in range(x, px + 1):
                grid[i][y] = 1
        else:
            for i in range(x, px - 1, -1):
                grid[i][y] = 1
        px = x; py = y

c = 0
while(not grid[200][0]):
    c += 1
    px = 200; py = 0
    while (True):
        if(py == (my + 1)):
            grid[px][py] = 2
            break
        if(not grid[px][py + 1]):
            py += 1
        elif(not grid[px - 1][py + 1]):
            px -= 1
            py += 1
        elif(not grid[px + 1][py + 1]):
            px += 1
            py += 1
        else: 
            grid[px][py] = 2
            break

print(c)