a,b = map(int,input().split())

s=a+b;
p=a*b;

if s>p:
    print('S')
elif s<p:
    print('P')
else:
    print('E')

