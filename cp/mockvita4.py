arr = list(map(int,input().split( )))

arr = sorted(arr,reverse = True)

l,a,b,j,ans = len(arr),0,0,0,0

for i in range(0,l):

	if(i%2==0):
		a+= arr[i];
	else:
		b+= arr[i];

ans = max(a,b)

print(ans)