t = int(input())

while(t>0):

    t-=1

    n,s = input().split( )
    n,s = int(n),int(s)

    price = list(map(int,input().split( )))
    flag = list(map(int,input().split( )))

    minf,mind=200,200

    for i in range(n):

        if(flag[i]):
            if(price[i]<minf):
                minf=price[i]

        else:
            if(price[i]<mind):
                mind=price[i]

        i+=1

    if((s+mind+minf)>100):
        print("no")
    else:
        print("yes")