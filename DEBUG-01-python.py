def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    A = set()

    for i in range(n):
        if a[i] == 1:
            continue

        sum_bits = 0
        temp = a[i]
        while temp > 0:
            if temp % 2 == 1:
                sum_bits += 1
            temp //= 2 
        if sum_bits <= 2:
            A.add(a[i])
        

    print(len(A))

main()
