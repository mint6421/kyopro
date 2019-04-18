
n = int(input())

a=0
b=0
c=0
flag = True

for i in range(n):
    t,x,y = map(int,input().split())
    t-=a
    x-=b
    y-=c
    if t< x+y or t % 2 != (x+y)%2 :
        flag = False
    else :
        a=t
        b=x
        c=y

if flag :
    print("Yes")
else :
    print("No")

