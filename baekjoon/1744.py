import sys
input = sys.stdin.readline
n = int(input())
nums = [int(input()) for _ in range(n)]
minus = []
plus = []
has_zero = 0
for i, v in enumerate(nums):
    if v > 0:
        plus.append(nums[i])
    elif v < 0:
        minus.append(nums[i])
    else:
        has_zero = 1
    
total = 0
minus.sort()
plus.sort()
# minus
while minus:
    if len(minus) >= 2:
        a, b = minus[0], minus[1]
        total += a * b
        del minus[0:2]
    elif len(minus) == 1:
        if has_zero != 1:
            total += minus[0]
        del minus[0]


while plus:
    if len(plus) >= 2:
        a, b = plus.pop(), plus.pop()
        if a == 1 or b == 1:
            total += a + b
        else:
            total += a * b
    elif len(plus) == 1:
        total += plus.pop()

print(total)

# 그리디 알고리즘
# 많은 조건 분기
    
