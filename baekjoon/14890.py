import sys
input = sys.stdin.readline
n, l = map(int, input().split())
path = []
for i in range(n):
    path.append(list(map(int, input().split())))

def possible(p):
    cont = 0
    prev = None
    for i in p:
        if prev != i:
            if cont < l and prev is not None:
                return False
            prev = i
            cont = 1
        else:
            cont += 1
    print(p)
    return True

paths = []
for i in range(n):
    paths.append(path[i])
for i in range(n):
    new_path = []
    for j in range(n):
        new_path.append(path[j][i])
    paths.append(new_path)

result = sum(map(lambda x: possible(x), paths))
print(result)