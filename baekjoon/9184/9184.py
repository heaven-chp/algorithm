import sys

global memoization
memoization = dict()


def w(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1

    key = str(a) + "-" + str(b) + "-" + str(c)
    if key in memoization:
        return memoization[key]

    if a > 20 or b > 20 or c > 20:
        memoization[key] = w(20, 20, 20)
        return memoization[key]

    if a < b and b < c:
        memoization[key] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)
        return memoization[key]

    memoization[key] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(
        a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)
    return memoization[key]


if __name__ == "__main__":
    while True:
        a, b, c = map(int, sys.stdin.readline().split())
        if a == -1 and b == -1 and c == -1:
            break
        print('w(%d, %d, %d) = %d' % (a, b, c, w(a, b, c)))
