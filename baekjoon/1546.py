import sys
input = sys.stdin.readline
N = int(input())
arr = list(map(int, input().split()))
s = sum(arr); m = max(arr);
print(s/m*100/len(arr))