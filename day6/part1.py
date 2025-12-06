import re

with open('in.txt', 'r') as file:
    ans = 0
    arr = []
    for line in file:
        item = list(re.split(r'\s+', line.strip()))
        arr.append(item)
        
    for i in range(len(arr[-1])):
        symbol = arr[-1][i]
        # print(symbol, arr[0][i])
        tmp = int(arr[0][i])
        for j in range(1, len(arr)-1):
            if symbol == '*':
                tmp = tmp * int(arr[j][i])
            if symbol == '+':
                tmp = tmp + int(arr[j][i])
        ans = ans + tmp
    print(ans)