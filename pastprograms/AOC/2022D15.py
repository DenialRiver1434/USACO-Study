import sys

def finddist(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

def test(x1, y1):
    found = True
    for x, y, dist in op:
        if(finddist(x1, y1, x, y) <= dist):
            found = False
            break
    return found

beacons = set()

impossible = set()
op = []
N, M = map(int, input().split(" "))
for i in range(N):
    a, b, c, d = map(int, input().split(","))
    space = finddist(a, b, c, d)
    op.append((a, b, space))

for i in range(N):
    for j in range(i + 1, N):
        a, b, c = op[i]
        m, n, d = op[j]
        if(((c + d + a + b + n - m) % 2) == 0):
            y1 = (c + d + a + b + n - m) // 2
            x1 = c + a + b - y1
            if(test(x1, y1 + 1) and (x1 >= 0) and (x1 <= M) and ((y1 + 1) >= 0) and ((y1 + 1) <= M)):
                print(x1, y1 + 1)
                sys.exit()
        if(((a + m - n + b + c + d) % 2) == 0):
            x1 = (a + m - n + b + c + d) // 2
            y1 = c + a + b - x1
            if(test(x1 + 1, y1) and ((x1 + 1) >= 0) and ((x1 + 1) <= M) and ((y1) >= 0) and ((y1) <= M)):
                print(x1 + 1, y1)
                sys.exit()
        if(((c + d - a - m - b + n) % 2) == 0):
            x1 = -(c + d - a - m - b + n) // 2
            y1 = -c + a + b - x1
            if(test(x1 - 1, y1) and ((x1 - 1) >= 0) and ((x1 - 1) <= M) and ((y1) >= 0) and ((y1) <= M)):
                print(x1 - 1, y1)
                sys.exit()
        if(((c + d + m - a - n - b) % 2) == 0):
            y1 = -(c + d + m - a - n - b) // 2
            x1 = -c + a + b - y1
            if(test(x1, y1 - 1) and (x1 >= 0) and (x1 <= M) and ((y1 - 1) >= 0) and ((y1 - 1) <= M)):
                print(x1, y1 - 1)
                sys.exit()