
n,y = map(int,input().split())

a=-1
b=-1
c=-1

for i in range(n+1) :
    for j in range(n+1-i):
        sum = i*1000+j*5000
        k = (y-sum)//10000
        if(k != (y-sum)/10000):
            continue
        if(i+j+k == n) :
            a = k
            b = j
            c = i


print(a,b,c)

