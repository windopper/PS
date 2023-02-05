import sys
from collections import defaultdict
input = sys.stdin.readline
n = int(input())
net = defaultdict(list)
for i in range(int(input())):
    s, e = map(int, input().split())
    net[s].append(e)
    net[e].append(s)

cnt = 0
visited = []
def dfs(x):
    global cnt
    cnt += 1
    visited.append(x)
    for nxt in net[x]:
        if nxt in visited:
            continue
        dfs(nxt)
        
dfs(1)
print(cnt)