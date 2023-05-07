from typing import Callable

fin = open("angry.in", 'r')
fout = open("angry.out", 'w')

def first_true(lo: int, hi: int, f: Callable[[int], bool]) -> int:
	hi += 1
	while lo < hi:
		mid = (lo + hi) // 2
		if f(mid):
			hi = mid
		else:
			lo = mid + 1
	return lo

def attempt(n):
    global nums
    global N
    global M

    startv, bus = nums[0], 1
    for i in range(1, N):
        if((nums[i] - startv) > n * 2): 
            bus += 1
            startv = nums[i]
    return bus <= M

N, M= map(int, fin.readline().split(" "))
nums = sorted([int(fin.readline()) for i in range(N)])

fout.write(str(first_true(1, max(nums), lambda x: attempt(x))))
fin.close()
fout.close()