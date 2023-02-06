import sys, math
input = sys.stdin.readline
for _ in range(int(input())):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    dist = math.sqrt((x1-x2)**2 + (y1-y2)**2)
    if x1 == x2 and y1 == y2 and r1 == r2:
        print(-1)
    elif dist + r1 < r2 or r2 + r1 < dist:
        print(0)
    elif dist - r1 == r2:
        print(1)
    else:
        print(2)