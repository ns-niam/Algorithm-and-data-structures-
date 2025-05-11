from collections import deque

b = deque()
n = deque()
cnt = 0

# Reading inputs for b deque
for i in range(5):
    b.append(int(input()))

# Reading inputs for n deque
for i in range(5):
    n.append(int(input()))

while b and n:
    num1 = b[0]
    num2 = n[0]

    if num1 > num2:
        if num1 == 9 and num2 == 0:
            n.append(num1)
            n.append(num2)
            b.popleft()
            n.popleft()
        else:
            b.append(num1)
            b.append(num2)
            b.popleft()
            n.popleft()
    elif num1 < num2:
        if num1 == 0 and num2 == 9:
            b.append(num1)
            b.append(num2)
            b.popleft()
            n.popleft()
        else:
            n.append(num1)
            n.append(num2)
            b.popleft()
            n.popleft()

    cnt += 1
    if cnt == 1000000:
        print("blin nichya")
        break

if not b:
    print(f"n {cnt}")
else:
    print(f"b {cnt}")
