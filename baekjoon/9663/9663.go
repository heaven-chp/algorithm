package main

import (
	"bufio"
	"fmt"
	"os"
)

func promising(board []int, currentRow int) bool {
	for i := 0; i < currentRow; i++ {
		if board[i] == board[currentRow] ||
			i-currentRow == board[i]-board[currentRow] ||
			(i-currentRow)*-1 == board[i]-board[currentRow] {
			return false
		}
	}

	return true
}

func dfs(board []int, currentRow, boardSize int, result *int) {
	if currentRow == boardSize {
		*result++
	}

	for i := 0; i < boardSize; i++ {
		board[currentRow] = i
		if promising(board, currentRow) {
			dfs(board, currentRow+1, boardSize, result)
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	N := 0
	fmt.Fscanln(reader, &N)

	board := make([]int, 15)

	result := 0
	dfs(board, 0, N, &result)

	fmt.Fprintln(writer, result)
}
