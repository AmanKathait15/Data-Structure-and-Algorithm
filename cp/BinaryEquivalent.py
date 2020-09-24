from itertools import combinations
from math import log2 
from sys import stdout,stdin

n = int(stdin.readline())
arr = list(map(int,stdin.readline().split( )))

ones,m = [],0

for i in range(n):

	ones.append(bin(arr[i]).count('1'))

	if(arr[i]>m):
		m = arr[i]

m = int(log2(m)+1)

#print(m)
count = 0

for i in range(n):

	if(ones[i]*2 == m):

		count+=1

for i in range(2,n+1):

	arr = list(combinations(ones,i))

	for j in arr:

		if(sum(j)*2 == m*i):

			count+=1

ans = bin(count).replace('0b','')

m = m-len(ans)

tmp = ''
for i in range(m):
	tmp+='0'
tmp += ans

stdout.write(tmp+"\n")