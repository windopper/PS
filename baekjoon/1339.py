import sys
import heapq
input = sys.stdin.readline
n = int(input())
words = [input().strip() for _ in range(n)]
max_length = max(map(len, words))
rjusted_words = list(map(lambda x: x.rjust(max_length), words))
num = 9
dic = {}
seq = []
for i in range(max_length):
    for j in range(n):
        seq.append(rjusted_words[j][i])
seq = seq[::-1]
while seq:
    token = seq.pop()
    if token == ' ':
        continue
    if token not in dic:
        dic[token] = num
        num -= 1

result = 0
for word in words:
    value = ''.join(list(map(lambda x: str(dic[x]), word)))
    result += int(value)
print(result)