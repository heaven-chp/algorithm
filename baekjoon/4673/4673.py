import sys


def add(number1, number2):
    return number1 + number2


if __name__ == "__main__":
    A, B = map(int, sys.stdin.readline().split())

    print(add(A, B))
