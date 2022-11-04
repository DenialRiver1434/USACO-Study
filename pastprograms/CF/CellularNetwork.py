N, M = map(int, input().split(" "))
towns = [int(l) for l in input().split(" ")]
towers = [int(l) for l in input().split(" ")]
worst = max(towns) - max(towers)
left = -10000000000000
while(towers):
    now = towns.pop(0)
    if(abs(now - left) > abs(now - towers[0])): left = towers.pop(0)
    worst = max(worst, abs(left - now))
print(worst)