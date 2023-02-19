import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

move = [-1, 0, 1]

for i in range(int(input())):
    x, y = map(int, input().split())

    cnt = 1e9

    def dfs(before_move, loc, c):
        global cnt
        if c > cnt:
            return
        if loc == y and before_move == 1:
            cnt = min(cnt, c)
            return
        if loc > y:
            return

        for m in move:
            nxt = before_move + m
            if nxt <= 0:
                continue
            dfs(nxt, loc + nxt, c + 1)

    dfs(0, x, 0)

    print(cnt)