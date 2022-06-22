import sys


def main():
    expression = list(map(str, sys.stdin.readline().strip().split('-')))

    result = 0
    for num in expression[0].split('+'):
        result += int(num)

    for exp in expression[1:]:
        for num in exp.split('+'):
            result -= int(num)

    print(result)


if __name__ == "__main__":
    main()
