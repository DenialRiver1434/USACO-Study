import math

def div3(num):
    return num % 9699690

count = [0, 0, 0, 0, 0, 0, 0, 0]
items = [[53, 89, 62, 57, 74, 51, 83, 97], [85, 94, 97, 92, 56], [86, 82, 82], [94, 68], [83, 62, 74, 58, 96, 68, 85], [50, 68, 95, 82], [75], [92, 52, 85, 89, 68, 82]]
for i in range(10000):
    for j in range(8):
        if(j == 0):
            while(items[j]):
                count[j] += 1
                item = items[j][0]
                items[j] = items[j][1:]
                if(div3(item * 3) % 13 == 0):
                    items[1].append(div3(item * 3))
                else:
                    items[5].append(div3(item * 3))
        elif(j == 1):
            while(items[j]):
                count[j] += 1
                item = items[j][0]
                items[j] = items[j][1:]
                if(div3(item + 2) % 19 == 0):
                    items[5].append(div3(item + 2))
                else:
                    items[2].append(div3(item + 2))
        elif(j == 2):
            while(items[j]):
                count[j] += 1
                item = items[j][0]
                items[j] = items[j][1:]
                if(div3(item + 1) % 11 == 0):
                    items[3].append(div3(item + 1))
                else:
                    items[4].append(div3(item + 1))
        elif(j == 3):
            while(items[j]):
                count[j] += 1
                item = items[j][0]
                items[j] = items[j][1:]
                if(div3(item + 5) % 17 == 0):
                    items[7].append(div3(item + 5))
                else:
                    items[6].append(div3(item + 5))
        elif(j == 4):
            while(items[j]):
                count[j] += 1
                item = items[j][0]
                items[j] = items[j][1:]
                if(div3(item + 4) % 3 == 0):
                    items[3].append(div3(item + 4))
                else:
                    items[6].append(div3(item + 4))
        elif(j == 5):
            while(items[j]):
                count[j] += 1
                item = items[j][0]
                items[j] = items[j][1:]
                if(div3(item + 8) % 7 == 0):
                    items[2].append(div3(item + 8))
                else:
                    items[4].append(div3(item + 8))
        elif(j == 6):
            while(items[j]):
                count[j] += 1
                item = items[j][0]
                items[j] = items[j][1:]
                if(div3(item * 7) % 5 == 0):
                    items[7].append(div3(item * 7))
                else:
                    items[0].append(div3(item * 7))
        else:
            while(items[j]):
                count[j] += 1
                item = items[j][0]
                items[j] = items[j][1:]
                if(div3(item * item) % 2 == 0):
                    items[0].append(div3(item * item))
                else:
                    items[1].append(div3(item * item))
print(count)