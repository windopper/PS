import sys
from collections import Counter
import heapq
input = sys.stdin.readline
n, k = map(int, input().split())
arr = list(map(int, input().split()))

plugs = []
cnt = 0
for i, j in enumerate(arr):

    if j in plugs:
        continue

    if len(plugs) < n:
        plugs.append(j)
        continue
    
    remains = arr[i:]
    find_idx = []
    for k, plug in enumerate(plugs):
        if plug in remains:
            find_idx.append(remains.index(plug))
        else:
            find_idx.append(101)

    plug_out_idx = find_idx.index(max(find_idx))
    del plugs[plug_out_idx]
    plugs.append(j)
    cnt += 1

print(cnt)