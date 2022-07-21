str = input()

suffixlist = []

for i in range(len(str) - 1, -1, -1):
    suffixlist.append(str[i:])

suffixlist.sort()

for suffix in suffixlist:
    print(suffix)