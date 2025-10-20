n = int(input())
for i in range(1, n):
    print(' '*(i - 1), end='')
    print('*'*(n - i + 1), end='')
    print('*'*(n - i))
    # print(' '*(i - 1))
for i in range(n, 0, -1):
    print(' '*(i - 1), end='')
    print('*'*(n - i), end='')
    print('*'*(n - i + 1))
    # print(' '*(i - 1))
