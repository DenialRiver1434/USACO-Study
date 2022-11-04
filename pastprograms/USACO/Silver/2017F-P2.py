def upperbound(array, x):
    L = 0
    R = len(array)
    while L<R:
        mid = (R+L)//2
        if x >= array[mid] :
            L = mid + 1
        else:
            R = mid
    return L

fin = open("sample.in", 'r')
fout = open("sample.out", 'w')
N, interval, K = map(int, fin.readline().split(" "))
broken = sorted([int(fin.readline()) - 1 for i in range(K)])
for i in range(len(broken)):
    end = broken[i] + interval
    if(end >= N): break
    endi = upperbound(broken, end)
    K = min(K, (endi - i - 1))
fout.write(str(K))