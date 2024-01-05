n, k = map(int, input().strip().split())
s1 = str(n)
f = [0] * 10
temp =[]
for i in range(0, k):
    item = int(input())
    temp.append(item)

for i in range(k):
    while temp[i] > 0:
        f[temp[i] % 10] += 1
        temp[i] //= 10

p = 9
i = 0
while i < len(s1):
    while p > int(s1[i]):
        for j in range(f[p]):
            print(p, end='')
        p -= 1

    print(s1[i], end='')
    i += 1

while p != -1:
    for i in range(f[p]):
        print(p, end='')
    p -= 1
