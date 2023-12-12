import time

fin = open("lineup.in", 'r')
logtext = fin.read().splitlines()
if (len(logtext) == 0):
    logtext = input().splitlines()

st = time.time()
tc = 0
jx = 0
for line in logtext:
    xinp = line.split(" ")[0]
    xnums = (line.split(" ")[1]).split(',')

    inp = ""
    nums = []
    for i in range(5):
        nums = nums + xnums 
        inp = inp + xinp + "?"
    inp = inp[:-1]

    for i in range(len(nums)):
        nums[i] = int(nums[i])
    
    dp = [[[0 for k in range(250)] for j in range(250)] for i in range(250)]
    if (inp[0] == '?'):
        dp[0][0][0] = 1
        dp[0][0][1] = 1
    if (inp[0] == '.'):
        dp[0][0][0] = 1
    if (inp[0] == '#'):
        dp[0][0][1] = 1
    
    for i in range(1, len(inp)):
        curchar = inp[i]
        for curset in range(len(nums)):
            for completed in range(nums[curset] + 1):
                if (inp[i] == '?' or inp[i] == '.'):
                    if (completed == nums[curset]):
                        dp[i][curset + 1][0] += dp[i - 1][curset][completed]
                    if (completed == 0):
                        dp[i][curset][0] += dp[i - 1][curset][completed]
                if (inp[i] == '?' or inp[i] == '#'):
                    if (completed < nums[curset]):
                        dp[i][curset][completed + 1] += dp[i - 1][curset][completed]
        if (inp[i] == '?' or inp[i] == '.'):
            dp[i][len(nums)][0] += dp[i - 1][len(nums)][0]
    # print(dp[len(inp) - 1][len(nums) - 1][nums[len(nums) - 1]] + dp[len(inp) - 1][len(nums)][0])
    tc += (dp[len(inp) - 1][len(nums) - 1][nums[len(nums) - 1]] + dp[len(inp) - 1][len(nums)][0])

    if (jx % 10 == 0):
        print(str(jx / 10) + "% done")
        print("Time elapsed:", time.time() - st, "seconds")
    jx += 1

print(tc)