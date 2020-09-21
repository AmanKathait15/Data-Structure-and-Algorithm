from itertools import permutations

n = int(input())

while(n>0):

  n-=1

  li = sorted(list(input()))

  li = list(permutations(li,2))

  output = ""

  for tup in li:

    output+= ''.join(tup) + " "

  print(output)

