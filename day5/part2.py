with open('in.txt', 'r') as file:
    arr = []
    new_arr = []
    ans = 0
    
    for line in file:
        x = line.strip()
        if('-' in x):
            arr.append(list(map(int, x.split("-"))))
        
        if x == '': break
              
    arr.sort()
    # print(arr)
    start = arr[0][0]
    end = arr[0][1]
    
    for i in range(len(arr)-1):
        if(arr[i][1] < arr[i+1][0]):
            new_arr.append([start, max(end, arr[i][1]) ])
            start = arr[i+1][0]
            end = arr[i+1][1]
        else:
            end = max(end, arr[i][1])
            continue
        
    new_arr.append([start, max(end, arr[-1][1])])
    # print(new_arr)
    
    for i in range(len(new_arr)):
        ans = ans + new_arr[i][1] - new_arr[i][0] + 1
        
    print(ans)
    