import sys
input = sys.stdin.readline
x, y, w, h = map(int, input().split())
print(min([abs(y-h), abs(x-w), y, x]))