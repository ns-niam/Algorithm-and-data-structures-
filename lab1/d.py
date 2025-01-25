s = input()
st = []

for char in s:
    if st and st[-1] == char:
        st.pop()
    else:
        st.append(char)

print("YES" if not st else "NO")
