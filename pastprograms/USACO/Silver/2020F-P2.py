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

fin = open("triangles.in", 'r')
fout = open("triangles.out", 'w')
tc = 0
N = int(fin.readline())
unordered = []
xm = {}
ym = {}

for i in range(N):
    a, b = map(int, fin.readline().split(" "))
    unordered.append((a, b))
    if(a not in xm): xm[a] = [b]
    else:
        l = xm[a]
        insertion = lowerbound(l, b)
        xm[a].insert(insertion, b)
    if(b not in ym): ym[b] = [a]
    else:
        l = ym[b]
        insertion = lowerbound(l, a)
        ym[b].insert(insertion, a)

for x, y in unordered:
    xr = xm[x] # The list of y's on the same vertical line
    yr = ym[y] # The list of x's on the same horizontal line
    splita = lowerbound(xr, y)
    splitb = lowerbound(yr, x)
    xlow, xhigh = xr[:splita], xr[splita + 1:] # Use y
    ylow, yhigh = yr[:splita], yr[splita + 1:] # Use x
    sa = (len(xlow) * x - sum(xlow)) + (sum(xhigh) - len(xhigh) * x)
    sb = (len(ylow) * y - sum(ylow)) + (sum(yhigh) - len(yhigh) * y)
    tc += sa * sb
fout.write(str(tc % (10 ** 9 + 7)))