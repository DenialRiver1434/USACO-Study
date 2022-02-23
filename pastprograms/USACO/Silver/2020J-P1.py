def closest(array, x):
    best = 10 ** 19
    choice = -1
    for i in range(len(array)):
        a = array[i]
        if(a > x): 
            if(a - x < best):
                best = a - x
                choice = i
    return (best, choice)

N = int(input())
for i in range(N):
    a, b = map(int, input().split(" "))
    if(a == b):
        print(0)
        continue
    pasta = [a]
    pastb = [b]
    while(a > 1):
        if(a % 2 == 1): a += 1
        else: a //= 2
        pasta.append(a)
    while(b > 1):
        if(b % 2 == 1): b -= 1
        else: b //= 2
        pastb.append(b)
    best = 10 ** 19
    for j in range(len(pasta)):
        pos = pasta[j]
        close, i = closest(pastb, pos)
        if(i == -1): continue
        close += (j + i)
        best = min(best, close)
    print(best)