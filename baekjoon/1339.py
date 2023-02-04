import sys
from collections import defaultdict
input = sys.stdin.readline
n = int(input())
words = [input().strip() for _ in range(n)]
max_length = max(map(len, words))
q = []
char_weight = defaultdict(int)
for word in words:
    skip = max_length - len(word)
    for i, k in enumerate(word):
        char_weight[k] += 10 ** (len(word) - i)

weights = sorted(char_weight.items(), key=lambda x: x[1], reverse=True)

char_num = {}
dec = 9
for i, j in weights:
    char_num[i] = str(dec)
    dec -= 1

total = 0
for word in words:
    value = int(''.join(map(lambda x: char_num[x], word)))
    total += value
print(total)