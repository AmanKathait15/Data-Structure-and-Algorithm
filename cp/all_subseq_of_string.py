# Python Implementation of the approach 
import itertools 

def Sub_Sequences(STR): 
	
	subseq , count = [] , len(STR)

	for l in range(2, len(STR)+1): 

		subseq.append(list(itertools.combinations(STR, l))) 
	
	for li in subseq:

		for tup in li:

			i,j,flag = 0,len(tup)-1,1

			while(i<j):

				if(tup[i]!=tup[j]):

					flag = 0
					break

				i+=1
				j-=1

			if(flag):

				count+=1

	return count

t = int(input())

while(t>0):

	t-=1

	s = input()

	print(Sub_Sequences(s))