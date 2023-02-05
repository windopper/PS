import sys

input = sys.stdin.readline
l = []
for i in range(int(input())):
    M, N, K = map(int, input().split())
    board = [[0] * M for _ in range(N)]
    for i in range(K):
        x, y = map(int, input().split())
        board[y][x] = 1

    cnt = 0
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    def dfs(x, y):
        if x<0 or x>=M or y<0 or y>=N:
            return
        if board[y][x] == 0:
            return
        board[y][x] = 0
        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y
            dfs(nx, ny)

    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                cnt += 1
                dfs(j, i)

    print(cnt)


