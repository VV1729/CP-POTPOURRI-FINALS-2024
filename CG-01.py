import math

def exp(b, e):
    ret = 1
    while e > 0:
        if (e % 2 == 1):
            ret = ret * b
        e = e // 2
        b = (b * b)
    return int(ret)

n = int(input())
if n == 1:
    print(1)
else:
    p = math.log(n) / math.log(3.0)
    p = int(p + 1)
    m = exp(3, p)
    while (p > 0 and m // 3 >= n):
        m = m // 3
        p -= 1

    num3 = p
    num2 = 0
    while m % 3 == 0 and (m // 3) * 2 >= n:
            m = (m // 3) * 2
            num3 -= 1
            num2 += 1
    print(2 * num2+3*num3)