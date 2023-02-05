import sys
input = sys.stdin.readline

dp = [[[0 for _ in range(102)] for _ in range(102)] for _ in range(102)]

while True:
    a, b, c = map(int, input().split())
    
    if a==-1 and b==-1 and c==-1:
        break

    def w(a, b, c):
        ra, rb, rc = a+50, b+50, c+50
        if a<=0 or b<=0 or c<=0:
            return 1
        if a>20 or b>20 or c>20:
            if dp[70][70][70] != 0:
                return dp[70][70][70]
            dp[70][70][70] = w(20, 20, 20)
            return dp[70][70][70]
        if a<b and b<c:

            if dp[ra][rb][rc-1] == 0:
                dp[ra][rb][rc-1] = w(a, b, c-1)
            
            if dp[ra][rb-1][rc-1] == 0:
                dp[ra][rb-1][rc-1] = w(a, b-1, c-1)
            
            if dp[ra][rb-1][rc] == 0:
                dp[ra][rb-1][rc] = w(a, b-1, c)

            return dp[ra][rb][rc-1] + dp[ra][rb-1][rc-1] - dp[ra][rb-1][rc]

        if dp[ra-1][rb][rc] == 0:
            dp[ra-1][rb][rc] = w(a-1, b, c)
        
        if dp[ra-1][rb-1][rc] == 0:
            dp[ra-1][rb-1][rc] = w(a-1, b-1, c)

        if dp[ra-1][rb][rc-1] == 0:
            dp[ra-1][rb][rc-1] = w(a-1, b, c-1)

        if dp[ra-1][rb-1][rc-1] == 0:
            dp[ra-1][rb-1][rc-1] = w(a-1, b-1, c-1)

        return dp[ra-1][rb][rc] + dp[ra-1][rb-1][rc] + dp[ra-1][rb][rc-1] - dp[ra-1][rb-1][rc-1] 
    
    print(f'w({a}, {b}, {c}) = {w(a, b, c)}')

    
