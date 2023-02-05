import sys
import heapq
import math
input = sys.stdin.readline
n, f = map(int, input().split())
bridge = [(0, 0, 0)]
for i in range(1, n+1):
    x, y = map(int, input().split())
    bridge.append((x, y, i))

dist = []
q = [(0, 0, 0, 0)]
# cost, x, y, bridge_id
end = False
while q:
    cost, x, y, bridge_id = heapq.heappop(q)
    if y == f:
        print(round(cost))
        end = True
        break
    if bridge_id in dist:
        continue
    dist.append(bridge_id)
    for k, b in enumerate(bridge):
        nx, ny, i = b
        if abs(nx-x)>2 or abs(ny-y)>2 or i in dist:
            continue
        next_dist = math.sqrt((x-nx)**2 + (y-ny)**2)
        alt = cost + next_dist
        heapq.heappush(q, (alt, nx, ny, i))
        del bridge[k]

if not end:
    print(-1)