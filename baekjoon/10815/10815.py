import sys

if __name__ == "__main__":
    N = int(sys.stdin.readline())
    n = set(map(int, sys.stdin.readline().split()))

    M = int(sys.stdin.readline())
    m = list(map(int, sys.stdin.readline().split()))

    for i in m:
        if i in n:
            print(1, end=' ')
        else:
            print(0, end=' ')
