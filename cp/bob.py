n = int(input())

a = list(map(int,input().split()))

c = 0

for i in range(n):
  
  for j in range(i+1,n):
    
    s1 = sum(list(map(int,bin(i)[2:].split())))

    print(s1)
    
    s2 = sum(list(map(int,bin(j)[2:].split())))

    print(s2)
    
    if s1 == s2:
      
      c += 1

print(c)