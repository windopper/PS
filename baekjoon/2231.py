import sys
input = sys.stdin.readline
n = int(input())
exist = False;
for i in range(1, n):
    x = str(i)
    tmp = i
    for s in x:
        tmp += int(s)
    if tmp == n:
        print(x)
        exist = True;
        break

if not exist:
    print(0)

