import sys


class GasStation:

    def __init__(self):
        self.N = int(sys.stdin.readline())

        self.length = list(map(int, sys.stdin.readline().split()))
        self.price = list(map(int, sys.stdin.readline().split()))

    def run(self):
        result = 0
        currentPrice = self.price[0]

        for i in range(0, self.N - 1):
            if currentPrice > self.price[i]:
                currentPrice = self.price[i]

            result += currentPrice * self.length[i]

        return result


def main():
    print(GasStation().run())


if __name__ == "__main__":
    main()
