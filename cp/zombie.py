def gcd(a,b): 
        
    if(b == 0):

    	if(a==1):
    		return True
    	else:
    		return False
    
    return gcd(b, a%b)



def solve(arr,n):

	for i in range(n):
		
		if(arr[i]>arr[i+1] and gcd(arr[i],arr[i+1])):

			return i



if __name__ == '__main__':

	arr = list(map(int,input().split( )))

	n = int(input())

	print(solve(arr,n))
