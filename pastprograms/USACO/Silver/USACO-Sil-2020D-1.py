import math

farms = int(input())
connection = {}
for i in range(farms - 1):
    a, b = map(int, input().split(" "))
    if(a not in connection): connection[a] = [b]
    else: connection[a].append(b)
    if(b not in connection): connection[b] = [a]
    else: connection[b].append(a)

count = farms - 1
for c in connection:
    if(c == 1): count += math.ceil(math.log(len(connection[c]) + 1, 2))
    else: count += math.ceil(math.log(len(connection[c]), 2))
print(count)