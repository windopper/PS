import sys
import heapq
input = sys.stdin.readline

n, k = map(int, input().split())
gems = []
for i in range(n):
    m, v = map(int, input().split())
    heapq.heappush(gems, (m, v))

backpacks = []
for i in range(k):
    c = int(input())
    backpacks.append(c)

backpacks.sort()
price = 0
wait_gems = []
for backpack in backpacks:
    while gems and backpack >= gems[0][0]:
        # 가장 가벼운 보석이 가방에 들어갈 수 있을 때 까지 반복
        heapq.heappush(wait_gems, -heapq.heappop(gems)[1])
        # 보석 가치의 내림차순으로 임시 보석 보관소에 저장
        # 저장된 보석은 다음 가방이 들어올 때 까지 유지된다
        # 이는 보석이 가치 순으로 정렬되어 있으므로 다음 가방에 
        # 넣을 수 있도록 하는 것이다.
    if wait_gems:
        price -= heapq.heappop(wait_gems)
    elif not gems:
        # 보석이 더 이상 없으면 더이상 가방에 들어갈 수 없다는
        # 뜻이므로 순회 종료
        break
print(price)
