import sys


def dfs(maxNumber, currentCount, MaxCount, result):
    if currentCount == MaxCount:
        for value in result:
            print(value, end=' ')
        print()
        return

    for i in range(1, maxNumber + 1):
        result.append(i)
        dfs(maxNumber, currentCount + 1, MaxCount, result)
        result.pop(currentCount)


if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().split())

    dfs(N, 0, M, list())
