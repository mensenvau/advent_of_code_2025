import re
from functools import reduce
import operator

def calc(tmp, symbol):
    result = 0 
    if symbol == "+":
        result = sum(tmp)

    elif symbol == "*":
        result = 1
        for x in tmp:
            result *= x
    return result 
    
with open('in.txt', 'r') as file:
    ans = 0
    mxl = 0
    arr = []
    for line in file:
        arr.append(line.replace("\n", ""))
        mxl = max(mxl, len(line.replace("\n", "")))
    print(arr)
    tmp = []
    symbol = ""
    for i in range(mxl):
        if len(arr[-1])>i and arr[-1][i] != ' ':
            print(symbol, tmp)
            ans = ans + calc(tmp, symbol)
            symbol = arr[-1][i]
            tmp = []
        num = 0
        for j in range(len(arr) - 1):
            if arr[j][i] == ' ':
                continue
            num = num * 10 + int(arr[j][i])
        if num != 0:
            tmp.append(num)
    ans = ans + calc(tmp, symbol)
    print(symbol, tmp)
    print(ans)