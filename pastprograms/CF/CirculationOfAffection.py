N = int(input())
word = input()
distances = {}
prev = {}
for i in range(len(word)):
    if(word[i] not in prev):
        prev[word[i]] = i
        distances[word[i]] = []
    else:
        distances[word[i]].append(i - prev[word[i]]  - 1)
        prev[word[i]] = i
for d in distances: 
    dd = sorted(distances[d])
    c = dd.count(0) + 1
    prev[d] = (0, c)
    distances[d] = dd[c - 1:]

K = int(input())
commands = []
for i in range(K):
    a, b = input().split(" ")
    commands.append((int(a), b))
commands.sort(key=lambda x:x[0])
print(commands)