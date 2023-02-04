import sys
input = sys.stdin.readline
n, m = map(int, input().split())
packages = []
singles = []
for i in range(m):
    package, single = map(int, input().split())
    packages.append(package)
    singles.append(single)

cheapest_package = min(packages)
cheapest_single = min(singles)

# 낱개로 6개 사는게 더 싸다면?
single6_is_cheaper_than_package = cheapest_package > 6 * cheapest_single
package_is_cheaper_than_single = cheapest_single > cheapest_package
price = 0
if n >= 6:
    if single6_is_cheaper_than_package:
        price += cheapest_single * 6 * (n // 6)
    else:
        price += cheapest_package * (n // 6)
    n %= 6

if cheapest_single * n > cheapest_package:
    price += cheapest_package
else:
    price += cheapest_single * n

print(price)