import sys

if __name__ == "__main__":
    N = int(sys.stdin.readline())

    memoization = [0] * (N + 1)

    for i in range(2, N + 1):
        memoization[i] = memoization[i - 1]

        if i % 2 == 0:
            memoization[i] = min(memoization[i], memoization[int(i / 2)])

        if i % 3 == 0:
            memoization[i] = min(memoization[i], memoization[int(i / 3)])

        memoization[i] += 1

    print(memoization[N])
