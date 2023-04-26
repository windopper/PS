def multiply_2(x):
    return x * 2

temp = [1, 2, 3, 4, 5]

temp = map(multiply_2, temp)

for i in temp:
    print(i)