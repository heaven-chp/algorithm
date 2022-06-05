import sys

if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().split())

    A = list(map(int, sys.stdin.readline().split()))
    dictA = dict()
    for value in A:
        dictA[value] = 0

    result = N + M
    B = list(map(int, sys.stdin.readline().split()))
    for value in B:
        if value in dictA:
            result -= 2

    print(result)
