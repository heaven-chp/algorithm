import sys


def fibonacci_recursion(n, count):
    if n == 1 or n == 2:
        count[0] += 1
        return 1

    return fibonacci_recursion(n - 1, count) + fibonacci_recursion(
        n - 2, count)


def fibonacci_dp(n, count):
    result = list()
    result.append(0)
    result.append(1)
    result.append(1)

    for i in range(3, n + 1):
        count[0] += 1
        result.append(result[i - 1] + result[i - 2])

    return result[n]


if __name__ == "__main__":
    n = int(sys.stdin.readline())

    countDP = [0]
    print(fibonacci_dp(n, countDP), countDP[0])
