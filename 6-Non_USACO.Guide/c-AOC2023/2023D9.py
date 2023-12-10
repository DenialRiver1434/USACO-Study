def nxt (xs):
    ts = []
    diff = -1
    good = True
    for i in range(len(xs) - 1):
        ts.append(str(int(xs[i + 1]) - int(xs[i])))
        if (diff == -1):
            diff = int(xs[i + 1]) - int(xs[i])
        elif (int(xs[i + 1]) - int(xs[i]) != diff):
            good = False
    if (good):
        return int(xs[0]) - diff
    else:
        return int(xs[0]) - nxt(ts)

fin = open("lineup.in", 'r')
logtext = fin.read().splitlines()
if (len(logtext) == 0):
    logtext = input().splitlines()

c = 0
for line in logtext:
    xs = line.split(" ")
    c += nxt(xs)
print(c)