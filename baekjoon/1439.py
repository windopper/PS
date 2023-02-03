import sys
input = sys.stdin.readline
s = input().strip()
prev_num = None
zero_cnt = 0
one_cnt = 0
for i in s:
    if prev_num != i:
        if i == '0':
            zero_cnt += 1
        else:
            one_cnt += 1
        prev_num = i

print(min(zero_cnt, one_cnt))
