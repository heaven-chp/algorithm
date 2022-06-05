import sys

if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().split())

    mapInfo = {}
    for i in range(N):
        mapInfo[sys.stdin.readline().strip()] = 0

    result = list()
    for i in range(M):
        name = sys.stdin.readline().strip()
        if name in mapInfo:
            result.append(name)

    result.sort()
    print(len(result))
    for i in result:
        print(i)
