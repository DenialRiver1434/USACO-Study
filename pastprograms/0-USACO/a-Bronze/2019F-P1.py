import math
def maxd(distance): return math.ceil(distance / 2)

fin, fout = open("herding.in", 'r'), open("herding.out", 'w')
a, b, c = map(int, fin.readline().split())
a, b, c = map(int, sorted([a, b, c]))

# Minimum value is always 2 moves unless if there is a perfect case
if(a + 2 == b + 1 == c): fout.write("0\n")
elif(b - a == 2 or c - b == 2): fout.write("1\n")
else: fout.write("2\n")

# Maximum value is the max of the two differences - 1
if(b - a == 1 and c - b == 1): fout.write("0\n")
elif(b - a == 1): fout.write(str(c - b - 1) + '\n')
elif(c - b == 1): fout.write(str(b - a - 1) + '\n')
else: fout.write(str(max(b - a, c - b) - 1) + "\n")