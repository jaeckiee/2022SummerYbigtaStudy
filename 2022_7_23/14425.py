str = input()
slist = str.split()
n = int(slist[0])
m = int(slist[1])

dict1 = dict()
result = 0

for i in range(0, n):
    tmpstr = input()
    dict1[tmpstr] = 1

for i in range(0, m):
    tmpstr = input()
    if tmpstr in dict1:
        result = result + 1

print(result)