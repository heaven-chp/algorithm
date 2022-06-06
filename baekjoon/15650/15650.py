import sys


def dfs(currentNumber, maxNumber, currentIndex, maxIndex, result):
    if currentIndex == maxIndex:
        for value in result:
            print(value, end=' ')
        print()
        return

    for i in range(currentNumber, maxNumber + 1):
        result.append(i)
        dfs(i + 1, maxNumber, currentIndex + 1, maxIndex, result)
        result.pop(currentIndex)


if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().split())

    dfs(1, N, 0, M, list())
