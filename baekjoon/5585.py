n = int(input())
target = 1000 - n
cnt = 0
for i in [500, 100, 50, 10, 5, 1]:
    if target >= i:
        cnt += target // i
        target %= i
print(cnt)
