a,b = map(int,input().split())

if(a*b<0):
  print(abs(a)//abs(b)*-1)
else:
  print(abs(a)//abs(b))

