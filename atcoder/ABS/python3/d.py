
import sys

n = int(input())

a = list(map(int,input().split()))

ans = sys.maxsize

for i in range(n):
    c = 0
    while (a[i]%2==0) :
        c+=1
        a[i]=a[i]/2
    ans = min(ans,c)

print(ans)

