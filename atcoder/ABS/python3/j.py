
s = input()
s = s[::-1]
strs = ['dream','dreamer','erase','eraser']
strs = [t[::-1] for t in strs]

while s:
    ans = True
    for i in range(4):
            if(s[0:len(strs[i])] == strs[i]):
                s = s[len(strs[i]):]
                ans = False
    if (ans) :
        break

if s :
    print("NO")
else :
    print("YES")
        
