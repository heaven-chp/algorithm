import sys

if __name__ == "__main__":
    S = sys.stdin.readline().strip()

    result = dict()
    for i in range(len(S)):
        for j in range(0, len(S) - i):
            part = S[j:j + i + 1]
            if part in result:
                result[part] += 1
            else:
                result[part] = 1

    print(len(result))
