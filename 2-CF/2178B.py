def tc ():
    inp = input().split("s")

    if (len(inp) == 1):
        print(1 + len(inp[0]) // 2)
        return 
    
    ans = 0
    ans += (len(inp[0]) + 1) // 2
    ans += (len(inp[-1]) + 1) // 2

    for i in range(1, len(inp) - 1):
        ans += len(inp[i]) // 2
    print(ans)

T = int(input())

for i in range(T):
    tc ()