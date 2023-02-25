for _ in range(int(input())):
    a, b = input().split()
    a = int(a)
    ans = ''
    for s in b:
        ans += ''.join([s for i in range(a)])
    print(ans)