

t = int(input())

while(t):

	t-=1

	n = int(input())

	dt,ndt = 0,0

	arr = list(map(int,input().split( )))

	for x in arr:

		if(x%3==0):
			dt+=1
		else:
			ndt+=1

	if(n==1 and dt==1):

		print("Yes\n")

	elif(dt>(ndt+1)):

		print("Yes\n")

	else:

		print("No")

