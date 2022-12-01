def permutation(lst):
    if len(lst) == 0:
        return []

    if len(lst) == 1:
        return [lst]
    
    l = []
    for i in range(len(lst)):
       m = lst[i]
       remLst = lst[:i] + lst[i+1:]
       for p in permutation(remLst):
           l.append([m] + p)
    return l

def upperbound(array, x):
    L = 0
    R = len(array)
    while L<R:
        mid = (R+L)//2
        if  x >= array[mid] :
            L = mid + 1
        else:
            R = mid
    return L

def lowerbound(array, x):
    L = 0
    R = len(array)
    while (L<R):
        mid = (R+L) // 2
        if x <= array[mid]:
            R = mid
        else :
            L = mid+1
    return L

def combineranges(a):
    a.sort()
    b = []
    for pair in sorted(a):
        if b and b[-1][1] >= pair[0] - 1:
            b[-1][1] = max(b[-1][1], pair[1])
        else:
            b.append([pair[0], pair[1]])
    return b

def primefactor(number):
    factors = {}
    c = 2
    while(number > 1):
        if(c > number ** 0.5 and c < number):
            c = number
        if(number % c == 0):
            number = number // c
            if(c not in factors): factors[c] = 1
            else: factors[c] += 1
        else: c += 1

    for f in factors:
        print(f, factors[f])

def subsets(parts):
    def oneand0(ol):
        if(ol == 1):
            return ["0", "1"]
        prev = oneand0(ol - 1)
        out = []
        for x in prev:
            out.append("0" + x)
        for y in prev:
            out.append("1" + y)
        return out
    possible = oneand0(len(parts))
    sub = []
    for p in possible:
        temp = []
        for i in range(len(parts)):
            if(p[i] == '1'): temp.append(parts[i])
        sub.append(temp)
    return sub

print(upperbound([3, 9, 9, 10, 12, 15], 9))