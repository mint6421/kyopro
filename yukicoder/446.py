flag = True
for _ in range(2):
    x = input()
    if x.isdigit() == False:
        flag=False
    elif x[0] == '0' and len(x) > 1:
        flag=False
    elif int(x) > 12345:
        flag=False

if flag: 
    print("OK")
else:
    print("NG")

