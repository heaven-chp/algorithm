import sys


def dfs(startNumber, maxNumber, currentCount, MaxCount, result):
    if currentCount == MaxCount:
        for value in result:
            print(value, end=' ')
        print()
        return

    for i in range(startNumber, maxNumber + 1):
        result.append(i)
        dfs(i, maxNumber, currentCount + 1, MaxCount, result)
        result.pop(currentCount)


if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().split())

    dfs(1, N, 0, M, list())
