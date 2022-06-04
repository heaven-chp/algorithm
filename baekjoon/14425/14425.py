import sys

if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().split())

    n = set()
    for i in range(N):
        n.add(sys.stdin.readline().strip())

    count = 0
    for i in range(M):
        if sys.stdin.readline().strip() in n:
            count += 1

    print(count)
