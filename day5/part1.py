with open('in.txt', 'r') as file:
    arr = []
    ans = 0
    
    for line in file:
        x = line.strip()
        # print("value = ", x)
        if('-' in x):
            arr.append(list(map(int, x.split("-"))))
        elif x!='':
            x = int(x)
            for item in arr:
                if item[0] <= x and x <= item[1]:
                    # print("find = ", x, item)
                    ans = ans + 1
                    break 
                    
    print(ans)