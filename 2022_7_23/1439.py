str = input()
result = 0

if len(str) > 0:
    if str[0] == '0':
        splitlist = str.split('0')
    else:
        splitlist = str.split('1')
    for str in splitlist:
        if len(str) > 0:
            result = result + 1
print(result)