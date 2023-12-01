fin = open("lineup.in", 'r')
fout = open("lineup.out", 'w')

# Edited code from USACO Guide with our own touches

COWS = ['Beatrice', 'Belinda', 'Bella', 'Bessie', 'Betsy', 'Blue', 'Buttercup', 'Sue']

cow_inds = {
    'Beatrice' : 0,
    'Belinda' : 1,
    'Bella' : 2,
    'Bessie' : 3,
    'Betsy' : 4,
    'Blue' : 5,
    'Buttercup' : 6,
    'Sue' : 7
}

neighbors = [[], [], [], [], [], [], [], []] # One for each of the 8 cows

N = int(fin.readline())
for i in range(N):
    words = fin.readline().split(' ')

    if ('\n' in words[-1]):
        words[-1] = words[-1][:-1] # Removing breakline character issues (Python L)

    cow1 = cow_inds[words[0]]
    cow2 = cow_inds[words[-1]]
    neighbors[cow1].append(cow2)
    neighbors[cow2].append(cow1)

order = []
added = [False for _ in range(len(COWS))]
for c in range(len(COWS)):
	"""
	Check that:
	1. This cow hasn't already been added yet.
	2. This cow could be the possible start of a chain.
	"""
	if not added[c] and len(neighbors[c]) <= 1:
		added[c] = True
		order.append(c)

		# If the chain length > 1, we keep on going
		if len(neighbors[c]) == 1:
			prev = c
			at = neighbors[c][0]
			while len(neighbors[at]) == 2:
				added[at] = True
				order.append(at)
				a, b = neighbors[at]
				at, prev = b if a == prev else a, at

			# Add the final element
			added[at] = True
			order.append(at)

for c in order:
    fout.write(COWS[c] + '\n')