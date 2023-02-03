import sys
input = sys.stdin.readline
n = int(input())
kms = [i for i in list(map(int, input().split()))]
prices = [i for i in list(map(int, input().split()))]

current_min_price = 1e9
min_price = min(prices[:-1])
cost = 0
for i in range(n-1):
    price = prices[i]
    km = kms[i]
    current_min_price = min(current_min_price, price)
    if price == min_price:
        remain_km = sum(kms[i:])
        cost += remain_km * price
        break
    else:
        cost += km * current_min_price

print(cost)
