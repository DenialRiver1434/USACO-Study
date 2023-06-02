N = int(input())
word = input()
words = list(set(list(word)))
using = [0 for i in range(len(words))]
key = {}
for i in range(len(words)): key[words[i]] = i
worst = N
left = right = 0
while(True):
    if(min(using) == 0):
        if(right == N): break
        using[key[word[right]]] += 1
        right += 1
    else:
        worst = min(right - left, worst)
        using[key[word[left]]] -= 1
        left += 1
print(worst)