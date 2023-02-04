import sys
input = sys.stdin.readline
n, m = map(int, input().split())
A = []
B = []
for i in range(n):
    A.append([int(i) for i in input()[:m]])
for i in range(n):
    B.append([int(i) for i in input()[:m]])

def flip(x, y):
    for i in range(y, y+3):
        for j in range(x, x+3):
            A[i][j] = 1 - A[i][j]

def same():
    for i in range(n):
        for j in range(m):
            if A[i][j] != B[i][j]:
                return False
    return True

cnt = 0
for i in range(n-2):
    for j in range(m-2):
        if A[i][j] != B[i][j]:
            flip(j, i)
            cnt += 1

if same():
    print(cnt)
else:
    print(-1)