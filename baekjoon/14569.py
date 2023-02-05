import sys
input = sys.stdin.readline
n = int(input())
subj = []
for _ in range(n):
    i = list(map(int, input().split()[1:]))
    ib = 0b00
    for j in i:
        ib |= 1 << j
    subj.append(ib)

m = int(input())

for _ in range(m):
    i = list(map(int, input().split()[1:]))
    ib = 0b00
    for j in i:
        ib |= 1 << j
    cnt = 0
    for sub in subj:
        if sub & ib == sub:
            cnt += 1
    print(cnt)

