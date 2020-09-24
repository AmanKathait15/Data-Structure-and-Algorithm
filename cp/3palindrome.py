

def ispalindrome(s):

	if(s == s[::-1]):

		return True

	else:

		return False


s = input()

l = len(s)

flag,i,j,k = 0,0,1,2

while(j<l):
	if(ispalindrome(s[0:j])):

		while(k<l):
			if(ispalindrome(s[j:k])):
				if(ispalindrome(s[k:l])):
					flag = 1
			if(flag):
				break
			else:
				k+=1
	if(flag):
		break
	else:
		j+=1

print(s[0:j],s[j:k],s[k:l])
