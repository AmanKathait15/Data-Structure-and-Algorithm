


t = int(input())
mod = 1000000007

while(t>0):
    t-=1

    n,a = input().split(" ")
    n,a = int(n),int(a)

    if(a==0):
        print("0")
        continue
    

    ans,j= a,1
    summ = 0

    for i in range(0,n):
        tmp = ans
        ans = pow(ans,j,mod)
        summ+= ans
        ans*= tmp
        #print(ans,j)
        i+=1
        j+=2

    print(summ%mod)
    
    