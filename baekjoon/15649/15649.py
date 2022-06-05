import sys


def dfs(currentIndex, maxIndex, maxNumber, result):
    if currentIndex == maxIndex:
        for i in range(maxIndex):
            print(result[i], end=' ')
        print()
        return

    for i in range(1, maxNumber + 1):
        if i in result:
            continue

        result.insert(currentIndex, i)
        dfs(currentIndex + 1, maxIndex, maxNumber, result)
        result.pop(currentIndex)


if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().split())

    result = list()
    dfs(0, M, N, result)
