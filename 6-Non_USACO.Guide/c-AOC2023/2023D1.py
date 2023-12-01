# Both part work

N = 1000 # 1000
c = 0
for i in range(N):
	l = input()
	l += "     "
	x = ""
	for i in range(len(l) - 5):
		numbers = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
		for k in range(len(numbers)):
			j = numbers[k]
			if (l[i:(i+len(j))] == j):
				x += str(k + 1)
		if (ord(l[i]) >= 48 and ord(l[i]) <= 57):
			x += l[i]
	c += 10 * int(x[0]) + int(x[-1])

print(c)