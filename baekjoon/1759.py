import sys
from itertools import combinations
import heapq
input = sys.stdin.readline
l, c = map(int, input().split())
chars = list(input().split())
aeiou = 'aeiou'
vowels = []
consonants = []
for char in chars:
    if char in aeiou:
        vowels.append(char)
    else:
        consonants.append(char)

q = []
for i in range(1, min(len(vowels), l - 2) + 1):
    for j in combinations(vowels, i):
        for k in combinations(consonants, l-i):
            result = [*j, *k]
            result.sort()
            heapq.heappush(q, result)

while q:
    print(''.join(heapq.heappop(q)))