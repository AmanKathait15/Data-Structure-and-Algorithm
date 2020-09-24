
# constellation

n = int(input())

a = []

a.append(input())
a.append(input())
a.append(input())

i,ans = 0,""

while(i<n):

	if(a[0][i]=='#' and a[1][i]=='#' and a[2][i]=='#'):

		ans += '#'

	elif(i+2 < n):

		if(a[0][i:i+3]==".*." and a[1][i:i+3]=='***' and a[2][i:i+3]=='*.*'):

			ans += 'A'
			i+=2

		if(a[0][i:i+3]=="***" and a[1][i:i+3]=='***' and a[2][i:i+3]=='***'):

			ans += 'E'
			i+=2

		if(a[0][i:i+3]=="***" and a[1][i:i+3]=='.*.' and a[2][i:i+3]=='***'):

			ans += 'I'
			i+=2

		if(a[0][i:i+3]=="***" and a[1][i:i+3]=='*.*' and a[2][i:i+3]=='***'):

			ans += 'O'
			i+=2

		if(a[0][i:i+3]=="*.*" and a[1][i:i+3]=='*.*' and a[2][i:i+3]=='***'):

			ans += 'U'
			i+=2

	i+=1

print(ans) 