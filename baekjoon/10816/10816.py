import sys

if __name__ == "__main__":
    N = int(sys.stdin.readline())
    n = list(map(int, sys.stdin.readline().split()))

    cardInfo = {}
    for i in n:
        if i in cardInfo:
            cardInfo[i] += 1
        else:
            cardInfo[i] = 1

    M = int(sys.stdin.readline())
    m = list(map(int, sys.stdin.readline().split()))

    for i in m:
        if i in cardInfo:
            print(cardInfo[i], end=' ')
        else:
            print(0, end=' ')
