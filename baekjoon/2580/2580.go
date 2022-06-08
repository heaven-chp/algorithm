package main

import (
	"bufio"
	"fmt"
	"os"
)

const boardLen int = 9

func promising(board [][]int, row, column int) bool {
	for i := 0; i < boardLen; i++ {
		if i != column && board[row][i] == board[row][column] {
			return false
		}

		if i != row && board[i][column] == board[row][column] {
			return false
		}
	}

	startRow := row - (row % 3)
	startColumn := column - (column % 3)
	for i := startRow; i <= startRow+2; i++ {
		for j := startColumn; j <= startColumn+2; j++ {
			if i != row && j != column && board[i][j] == board[row][column] {
				return false
			}
		}
	}

	return true
}

func dfs(board [][]int, xInfo, yInfo []int, count int, find *bool) {
	if count == len(xInfo) {
		*find = true

		for i := 0; i < boardLen; i++ {
			for j := 0; j < boardLen; j++ {
				fmt.Printf("%d ", board[i][j])
			}
			fmt.Println()
		}

		return
	}

	for i := 1; i <= boardLen; i++ {
		board[xInfo[count]][yInfo[count]] = i
		if promising(board, xInfo[count], yInfo[count]) {
			dfs(board, xInfo, yInfo, count+1, find)

			if *find {
				return
			}
		}
		board[xInfo[count]][yInfo[count]] = 0
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	board := make([][]int, boardLen)
	for i := 0; i < boardLen; i++ {
		board[i] = make([]int, boardLen)
	}

	xInfo := make([]int, 0)
	yInfo := make([]int, 0)

	for i := 0; i < boardLen; i++ {
		for j := 0; j < boardLen; j++ {
			fmt.Fscanf(reader, "%d", &board[i][j])

			if board[i][j] == 0 {
				xInfo = append(xInfo, i)
				yInfo = append(yInfo, j)
			}
		}
		fmt.Fscanln(reader)
	}

	find := false
	dfs(board, xInfo, yInfo, 0, &find)
}
