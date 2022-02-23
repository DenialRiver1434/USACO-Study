def lowerbound(x):
    global indivg
    L = 0
    R = len(indivg)
    while (L<R):
        mid = (R+L) // 2
        if x <= indivg[mid]:
            R = mid
        else :
            L = mid+1
    return L

def total(array):
    global grass
    c = 0
    for a in array: c += grass[a]
    return c

def test(point):
    global splita
    global splitb
    global indivg
    down = (splita + point) / 2
    up = (splitb + point) / 2
    left = lowerbound(down)
    right = lowerbound(up)
    return total(indivg[left:right])

grassc, nhojc, N = map(int, input().split(" "))
nhoj = []
indivg = []
possible = []
grass = {}
for i in range(grassc): 
    a, b = map(int, input().split(" "))
    grass[a] = b
    indivg.append(a)
for i in range(nhojc): 
    inp = int(input())
    if(inp in grass): grass.pop(inp)
    nhoj.append(inp)
nhoj.sort()
indivg.sort()

splita, splitb = lowerbound(nhoj[0]), lowerbound(nhoj[-1])
possible.append(total(indivg[:splita]))
possible.append(total(indivg[splitb:]))

for i in range(len(nhoj) - 1):
    start, end = nhoj[i], nhoj[i + 1]
    splita, splitb = lowerbound(start), lowerbound(end)
    between = indivg[splita:splitb]
    twopossible = total(between)
    if(splitb - splita > 1):
        onepossible = 0
        midpoint = (start + end) / 2
        for b in between:
            if(b < midpoint): onepossible = max(onepossible, test(2 * b - splita - 0.02))
            else: onepossible = max(onepossible, test(2 * b - splitb + 0.02))
        possible.append(twopossible - onepossible)
        possible.append(onepossible)
    else:
        possible.append(twopossible)

possible.sort(reverse=True)
print(sum(possible[:N]))