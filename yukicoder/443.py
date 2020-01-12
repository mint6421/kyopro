import math

s = str(input())
st = set()

for i in s:
    st.add(int(i))

ans = int(s)

if len(st) == 1:
    print(ans)
else:
    for i in st:
        for j in st:
            if i>j:
                ans = math.gcd(ans,9*(i-j))
    print(ans)

