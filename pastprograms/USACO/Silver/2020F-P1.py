import math

fin = open("swap.in", 'r')
fout = open('swap.out', 'w')

done = set()
uses = {}
cow, order, count = map(int, fin.readline().split(" "))
switch = [fin.readline().split(" ") for i in range(order)]
cows = [i for i in range(cow)]
for s in switch: cows = cows[:int(s[0]) - 1] + cows[int(s[0]) - 1:int(s[1])][::-1] + cows[int(s[1]):]

for c in cows:
    if(c not in done):
        going = []
        start = c
        done.add(c)
        going.append(c)
        cc = 1
        current = cows[c]
        while(current != c):
            done.add(current)
            going.append(current)
            current = cows[current]
            cc += 1
        effective = count % len(going)
        for i in range(len(going)):
            uses[going[i]] = going[(i + effective) % len(going)]
    if(len(done) == cow): break
for i in range(cow):
    fout.write(str(uses[i] + 1) + '\n')