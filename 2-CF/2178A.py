T = int(input())

for i in range(T):
    s = input()
    if (s.count("Y") > 1):
        print("no")
    else:
        print("yes")