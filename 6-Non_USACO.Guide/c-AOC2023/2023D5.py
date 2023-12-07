import bisect

def stage (pos, t):
	global stages

	fin = []
	for l, r in pos:
		for ll, rr, de in stages[t]:
			if (rr <= l): continue
			if (ll >= r): break

			if (ll > l):
				fin.append((l, ll))
				l = ll
			if (rr > r):
				fin.append((l + de, r + de))
				l = r
				break
			else:
				fin.append((l + de, rr + de))
				l = rr
		if (l != r):
			fin.append((l, r))
	fin.sort()
	return fin

fin = open("lineup.in", 'r')
logtext = fin.read().splitlines()
if (len(logtext) == 0):
    logtext = input().splitlines()

ts = (logtext[0].split(" "))[1:]
seeds = []
for i in range(0, len(ts), 2):
    seeds.append([(int(ts[i]), int(ts[i]) + int(ts[i + 1]))])

doc = 0
stages = [[] for i in range(7)]
for line in logtext[2:]:
	if (len(line) == 0): 
		doc += 1
		continue
	if (not line[0].isnumeric()):
		continue
	else:
		a, b, c = map(int, line.split(" "))
		stages[doc].append((b, b + c, a - b))

for i in range(7):
	stages[i].sort()

best = 10000000000000000000
for s in seeds:
	cur = s
	for t in range(7):
		cur = stage(cur, t)
	cur.sort()
	a, b = cur[0]
	best = min(best, a)

print(best) # Part a