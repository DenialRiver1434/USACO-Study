length = int(input())
coords = []

for i in range(length):
    a, b = map(int, input().split(" "))
    coords.append([a, b])
coords.sort(key=lambda x:x[0])

s = 2 ** length
for i in range(length):
    for j in range(i + 1, length):
        a, b = coords[i][1], coords[j][1]
        if(a > b): a, b = b, a

        good = coords[i + 1:j]
        before = coords[:i]
        g = 0
        c = 0
        for go in good:
            if(go[1] >= a and go[1] <= b):
                g += 1
        for be in before:
            if(be[1] >= a and be[1] <= b):
                c += 1

        if(g > 0):
            s -= (2 ** g - 1) * (2 ** c)
print(s)