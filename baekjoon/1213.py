from collections import Counter
s = list(input())
s.sort()
c = Counter(s)
odds = 0
cent = ''
for k, v in c.items():
    if v % 2 == 1:
        odds += 1
        cent = k
        s.remove(k)
if odds > 1:
    print("I'm Sorry Hansoo")
else:
    temp = ''
    for i in range(0, len(s), 2):
        temp += s[i]

    print(temp + cent + temp[::-1])
    


