N, target = map(int, input().split(" "))
numbers = [int(k) for k in input().split(" ")]
sum = start = end = tc = 0
while(True):
    if(sum > target): sum -= (numbers[start]); start += 1
    else: 
        if(end == N): break
        sum += (numbers[end]); end += 1
    if(sum == target): tc += 1
print(tc)