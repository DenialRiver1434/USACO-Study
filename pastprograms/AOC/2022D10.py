strengths = [1, 1]
N = int(input())

c = 1
for i in range(N):
    line = input().split(" ")
    strengths.append(c)
    if(len(line) == 2):
        c += int(line[1])
        strengths.append(c)

out = ""
for i in range(1, 41):
    if(abs(strengths[i] - i + 1) <= 1): out += '#'
    else: out += '.'
print(out)

out = ""
for i in range(41, 81):
    if(abs(strengths[i] - i + 41) <= 1): out += '#'
    else: out += '.'
print(out)

out = ""
for i in range(81, 121):
    if(abs(strengths[i] - i + 81) <= 1): out += '#'
    else: out += '.'
print(out)

out = ""
for i in range(121, 161):
    if(abs(strengths[i] - i + 121) <= 1): out += '#'
    else: out += '.'
print(out)

out = ""
for i in range(161, 201):
    if(abs(strengths[i] - i + 161) <= 1): out += '#'
    else: out += '.'
print(out)

out = ""
for i in range(201, 241):
    if(abs(strengths[i] - i + 201) <= 1): out += '#'
    else: out += '.'
print(out)

