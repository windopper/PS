import sys
from itertools import combinations
input = sys.stdin.readline
n, m = map(int, input().split())
city = []
chicken = []

for i in range(n):
    v = list(map(int, input().split()))
    for j, k in enumerate(v):
        if k == 2:
            v[j] = 0
            chicken.append((j, i))

    city.append(v)


min_dist = 1e9
for c in combinations(chicken, m):
    copied = city[:]
    for x, y in c:
        copied[y][x] = 2
    # 치킨 집 추가
    total = 0
    for i in range(n):
        for j in range(n):
            if copied[i][j] == 2:
                continue
            if copied[i][j] == 1:
                dist = 1e9
                for x, y in c:
                    dist = min(dist, abs(x-j) + abs(y-i))
                total += dist
    
    min_dist = min(min_dist, total)
print(min_dist)