def lowerbound(array, x):
    if(x < min(array)): return -1
    L = 0
    R = len(array)
    while (L<R):
        mid = (R+L) // 2
        if x <= array[mid]:
            R = mid
        else :
            L = mid+1
    return L

N, K = map(int, input().split(" "))
tickets = sorted([int(k) for k in input().split(" ")])
people = [int(i) for i in input().split(" ")]
for p in people:
    loc = lowerbound(tickets, p)
    if(loc == -1): print(-1)
    else: 
        if(p == tickets[loc]): 
            print(tickets[loc])
            tickets.pop(loc)
        else: 
            print(tickets[loc - 1])
            tickets.pop(loc - 1)