def tc ():
    N = int(input())
    a = input().split(" ")
    pref = [0]
    for i in range(N):
        a[i] = int(a[i])
        pref.append(pref[-1] + a[i])
    
    best = a[0]
    pre = 0
    for cutoff in range(N):
        if (cutoff == 1):
            pre = a[0]
        elif (cutoff > 1):
            pre += abs(a[cutoff - 1])
        best = max(best, pre + -(pref[N] - pref[cutoff + 1]))
    print(best)

T = int(input())

for i in range(T):
    tc ()