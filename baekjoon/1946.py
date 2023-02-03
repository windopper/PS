import sys
input = sys.stdin.readline
T = int(input())
for i in range(T):
    N = int(input())
    q = []
    for j in range(N):
        q.append(tuple(map(int, input().split())))
    q.sort(key=lambda x: -x[0])
    cnt = 1
    _, v = q.pop()
    while q:
        _, next_v = q.pop()
        if next_v < v:
            cnt += 1
            v = next_v
    print(cnt)
