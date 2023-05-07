from typing import Callable

fin = open("convention.in", 'r')
fout = open("convention.out", 'w')

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
    global C

    starti, startv, bus = 0, nums[0], 1
    for i in range(1, N):
        if((i - starti) >= C or (nums[i] - startv) > n): 
            bus += 1
            starti = i; startv = nums[i]
    return bus <= M

N, M, C = map(int, fin.readline().split(" "))
nums = sorted([int(i) for i in fin.readline().split(" ")])

fout.write(str(first_true(1, max(nums), lambda x: attempt(x))))
fin.close()
fout.close()