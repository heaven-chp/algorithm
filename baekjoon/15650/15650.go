package main

import (
	"bufio"
	"fmt"
	"os"
)

func dfs(writer *bufio.Writer, visited []bool, result []int, numberChoice, numberStart, numberEnd, index int) {
	if index == numberChoice {
		for _, value := range result {
			fmt.Fprintf(writer, "%d ", value)
		}
		fmt.Fprintf(writer, "\n")

		return
	}

	for i := numberStart; i <= numberEnd; i++ {
		if visited[i] {
			continue
		}

		result[index] = i

		visited[i] = true
		dfs(writer, visited, result, numberChoice, i, numberEnd, index+1)
		visited[i] = false
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	N := 0
	M := 0
	fmt.Fscanf(reader, "%d %d\n", &N, &M)

	visited := make([]bool, N+1)
	result := make([]int, M)
	dfs(writer, visited, result, M, 1, N, 0)
}
