import sys
from math import gcd

N = int(input())
nums = [int(i) for i in input().split(" ")]
if(N == 1):
    print(nums[0])
    sys.exit()

gcdto = [nums[0]]
gcdfrom = [nums[-1]]
for n in nums[1:]: gcdto.append(gcd(gcdto[-1], n))
nums = nums[::-1]
for n in nums[1:]: gcdfrom.insert(0, gcd(n, gcdfrom[0]))
best = max(gcdto[-2], gcdfrom[1])
for i in range(1, N - 1):
    left, right = gcdto[i - 1], gcdfrom[i + 1]
    best = max(best, gcd(left, right))
print(best)