import math

t = int(input())

def check(l,r,x,y):

    maximum,z = (x & l)*(y & l) , l

    for i in range(l+1,r+1):

        tmp = (x & i)*(y & i)

        if(tmp > maximum):
            maximum , z = tmp , i

        if(maximum == (x*y)):

            return z

    return z

def find_z(l,r,x,y):

    z = x | y

    print(z)

    if(z>=l and z<=r):

        return z

    elif(z<l):

        while(z<l):

            z+= 2**(int(math.log2(z))+1)

        return z

    else:

        return check(l,r,x,y)

while t>0:

    t-=1

    x,y,l,r = input().split()
    x,y,l,r = int(x),int(y),int(l),int(r)

    z = x | y

    print(z, check(l,r,x,y))

    print(bin(x),bin(y),bin(z))
