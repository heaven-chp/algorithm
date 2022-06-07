import sys

if __name__ == "__main__":
    N, K = map(int, sys.stdin.readline().split())

    value = list()
    for i in range(0, N):
        value.append(int(sys.stdin.readline()))

    result = 0
    for i in range(N - 1, -1, -1):
        result += int(K / value[i])
        K %= value[i]

    print(result)
