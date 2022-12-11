

visited = set()
positions = [(0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0), (0, 0)]

N = int(input())
for i in range(N):
    line = input().split(" ")
    dir = line[0]; num = int(line[1])
    for i in range(num):
        if(dir == "R"):
            x, y = positions[0]
            x += 1
            positions[0] = (x, y)
        elif(dir == "L"):
            x, y = positions[0]
            x -= 1
            positions[0] = (x, y)
        elif(dir == "U"):
            x, y = positions[0]
            y += 1
            positions[0] = (x, y)
        else:
            x, y = positions[0]
            y -= 1
            positions[0] = (x, y)
        for i in range(1, 10):
            headx, heady = positions[i - 1]
            tailx, taily = positions[i]
            if(headx == (tailx + 2)):
                if(heady == (taily + 2)):
                    tailx = headx - 1
                    taily = heady - 1
                elif(heady == (taily - 2)):
                    tailx = headx - 1
                    taily = heady + 1
                else:
                    tailx = headx - 1
                    taily = heady
            elif(headx == (tailx - 2)):
                if(heady == (taily + 2)):
                    tailx = headx + 1
                    taily = heady - 1
                elif(heady == (taily - 2)):
                    tailx = headx + 1
                    taily = heady + 1
                else: 
                    tailx = headx + 1
                    taily = heady
            elif(heady == (taily + 2)):
                taily = heady - 1
                tailx = headx
            elif(heady == (taily - 2)):
                taily = heady + 1
                tailx = headx
            positions[i] = (tailx, taily)
            if(i == 9): visited.add((tailx, taily))

print(len(visited))