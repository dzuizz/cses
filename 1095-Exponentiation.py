from sys import stdin

input = stdin.readline
MOD = 1000000007


def powIter(a, b) -> int:
    ret = 1
    while b > 0:
        if b & 1:
            ret = ret * a % MOD
        a = (a * a) % MOD
        b >>= 1
    return ret


def powRec(a, b) -> int:
    if b == 0:
        return 1
    if b & 1:
        return a * powRec(a, b - 1) % MOD
    x = powRec(a, b >> 1)
    return x * x % MOD


for _ in range(int(input())):
    a, b = map(int, input().split())
    if _ & 1:
        print(powIter(a, b))
    else:
        print(powRec(a, b))
