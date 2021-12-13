#O (n log n) accepted
cows, lowm, goodm, highm = map(int, input().split(" "))
combine = {}

#Read each of the endpoints
for i in range(cows):
    a, b = map(int, input().split(" "))
    b += 1 #The cow only feels hot 1 degree higher than the comfort range
    #To be able to add on all the values at once, we put everything into a ordered pair list [# of cows that start feeling comfort, #of cows that start feeling hot]
    if(a not in combine):
        combine[a] = [1, 0]
    else:
        combine[a][0] += 1
    if(b not in combine):
        combine[b] = [0, 1]
    else:
        combine[b][1] += 1

ret = sorted(combine.keys()) #sort the keys
final = {}
for r in ret:
    #assign the keys to "final" to get sorted dictionary
    final[r] = combine[r]

start = cows * lowm
out = [start]

for f in final:
    #go through each key in final
    pair = final[f]
    start += pair[0] * (goodm - lowm)
    start -= pair[1] * (goodm - highm)
    out.append(start)

print(max(out))