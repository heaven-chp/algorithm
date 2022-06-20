import sys


class DP():

    def __init__(self):
        self.N, self.K = map(int, sys.stdin.readline().split())
        self.dp = [[0] * (self.K + 1) for _ in range(self.N + 1)]

        self.W = [0]
        self.V = [0]

        for i in range(0, self.N):
            w, v = map(int, sys.stdin.readline().split())
            self.W.insert(i + 1, w)
            self.V.insert(i + 1, v)

    def run(self):
        for i in range(1, self.N + 1):
            for j in range(1, self.K + 1):
                if j < self.W[i]:
                    self.dp[i][j] = self.dp[i - 1][j]
                    continue

                self.dp[i][j] = max(self.dp[i - 1][j - self.W[i]] + self.V[i],
                                    self.dp[i - 1][j])

        return self.dp[self.N][self.K]


def main():
    print(DP().run())


if __name__ == "__main__":
    main()
