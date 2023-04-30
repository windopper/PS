set1 = {10, 20, 30}
set2 = [70] + list(set1)
set2.insert(3, 80)
temp = set2[2];
set2[2] = set2[4];
set2[4] = temp;
print(set2)