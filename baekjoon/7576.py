import sys
input = sys.stdin.readline
w, h = map(int, input().split())
arr = []
riped = []
no_riped = 0
empty = 0
for i in range(h):
    v = list(map(int, input().split()))
    for j in range(w):
        if v[j] == 1:
            riped.append((j, i))
        elif v[j] == 0:
            no_riped += 1
        else:
            empty += 1

    arr.append(v)

if w*h - empty == len(riped):
    print(0)
else:
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]
    days = 0

    while no_riped > 0 and riped:
        new_riped = []
        days += 1
        for x, y in riped:
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0<=nx<w and 0<=ny<h and arr[ny][nx] == 0:
                    arr[ny][nx] = 1
                    no_riped -= 1
                    new_riped.append((nx, ny))

        riped = new_riped
    
    if no_riped == 0:
        print(days)
    else:
        print(-1)