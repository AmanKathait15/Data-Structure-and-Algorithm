t = int(input())

for i in range(1,t+1):
    
    n,b = input().split(" ")
    n,b = int(n),int(b)
    
    arr = list(map(int,input().split()))
    
    arr.sort()
    l = len(arr)
    summ,count,j=0,0,0
    while(j<l and summ+arr[j]<=b):
        count+=1
        summ+=arr[j]
        j+=1
    
    print("Case #{}: {}".format(i,count))