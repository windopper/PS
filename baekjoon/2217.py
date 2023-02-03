import sys
input = sys.stdin.readline

n = int(input())
ropes = [int(input()) for _ in range(n)]
ropes.sort(reverse=True)
max_weight = 0
length = len(ropes)
while ropes:
    weakest = ropes.pop()
    max_weight = max(max_weight, weakest * length)
    length -= 1
    
print(max_weight)