n = int(input())
for i in range(n, 1, -1):
    print(' '*(i - 1), end='')
    print('*'*(n - i + 1), end='')
    print('*'*(n - i))
for i in range(1, n + 1):
    print(' '*(i - 1), end='')
    print('*'*(n - i + 1), end='')
    print('*'*(n - i))
