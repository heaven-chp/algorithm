import sys


class Sudoku:

    def __init__(self):
        self.find = False

        self.board = []
        for i in range(9):
            self.board.append(list(map(int, sys.stdin.readline().split())))

        self.zeroX = {}
        self.zeroY = {}
        self.zeroCount = 0
        for i in range(9):
            for j in range(9):
                if self.board[i][j] == 0:
                    self.zeroX[self.zeroCount] = i
                    self.zeroY[self.zeroCount] = j
                    self.zeroCount += 1

    def promising(self, row, column):
        for i in range(9):
            if i != column and self.board[row][i] == self.board[row][column]:
                return False
            if i != row and self.board[i][column] == self.board[row][column]:
                return False

        x = row - row % 3
        y = column - column % 3
        for i in range(x, x + 3):
            for j in range(y, y + 3):
                if i != row and j != column and self.board[i][j] == self.board[
                        row][column]:
                    return False

        return True

    def dfs(self, count):
        if count == self.zeroCount:
            self.find = True
            return

        for i in range(1, 10):
            self.board[self.zeroX[count]][self.zeroY[count]] = i
            if self.promising(self.zeroX[count], self.zeroY[count]):
                self.dfs(count + 1)
                if self.find:
                    return
            self.board[self.zeroX[count]][self.zeroY[count]] = 0

    def run(self):
        self.dfs(0)

        for i in range(9):
            for j in range(9):
                print(self.board[i][j], end=' ')
            print()


def main():
    Sudoku().run()


if __name__ == "__main__":
    main()
