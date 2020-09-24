t = int(input())

for i in range(1,t+1):
    
    k,n = input().split(" ")
    k,n = int(k),int(n)

    arr = []
    total = 2**k

    for i in range(k):

    	x,y = input().split(" ")
    	x,y = int(x),int(y)
    
    	arr.append((x,y))

    arr.sort()
    print(arr)
    count = 0

    for j in range(total):

    	summ = 0
    	s = bin(j).replace("0b","")
    	s = s[::-1]
    	print(s)
    	l,i = len(s),0

    	while(i<l):

    		if(s[i]=='0'):
    			summ+=arr[i][0]
    		else:
    			summ+=arr[i][1]
    		i+=1

    	while(i<k):
    		summ+=arr[i][0]
    		i+=1

    	print(summ)

    	if(summ<n):
    		count+=1
    	else:
    		break

    print(count)