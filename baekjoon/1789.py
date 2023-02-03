import sys
input = sys.stdin.readline
s = int(input())
total = 0
i = 1
li = []
while True:
    total += i
    if total > s:
        target = total - s
        print(li.pop())
        break
    elif total < s:
        li.append(i)
    else:
        print(i)
        break
    i += 1