import sys


class Dfs:

    def __init__(self):
        self.max = -sys.maxsize
        self.min = sys.maxsize

    def run(self, A, operator, count, result):
        if count == len(A):
            self.max = max(self.max, result)
            self.min = min(self.min, result)
            return

        for i in range(0, 4):
            if operator[i] == 0:
                continue

            operator[i] -= 1
            if i == 0:
                self.run(A, operator, count + 1, result + A[count])
            elif i == 1:
                self.run(A, operator, count + 1, result - A[count])
            elif i == 2:
                self.run(A, operator, count + 1, result * A[count])
            elif i == 3:
                self.run(A, operator, count + 1, int(result / A[count]))
            operator[i] += 1


def main():
    N = int(sys.stdin.readline())

    A = list(map(int, sys.stdin.readline().split()))

    operator = list(map(int, sys.stdin.readline().split()))

    dfs = Dfs()
    dfs.run(A, operator, 1, A[0])

    print(dfs.max)
    print(dfs.min)


if __name__ == "__main__":
    main()
