import sys
import heapq
input = sys.stdin.readline
n = int(input())
q = []
for i in range(n):
    s, t = map(int, input().split())
    q.append((s, t))
q.sort()
room = []
heapq.heappush(room, q[0][1])
for i in range(1, n):
    if q[i][0] < room[0]:
        # 가장 먼저 회의가 끝날 수 있는 시간보다
        # 다음 회의 시간이 빠르면 회의실 개설
        heapq.heappush(room, q[i][1])
        # 회의실 개설
    else:
        heapq.heappop(room)
        heapq.heappush(room, q[i][1])
    
print(len(room))
