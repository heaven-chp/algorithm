package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	N := 0
	M := 0
	fmt.Fscanln(reader, &N, &M)

	cumulativeSum := make([]int, N)

	fmt.Fscanf(reader, "%d", &cumulativeSum[0])
	for i := 1; i < N; i++ {
		fmt.Fscanf(reader, "%d", &cumulativeSum[i])
		cumulativeSum[i] += cumulativeSum[i-1]
	}

	fmt.Fscanln(reader)

	for k := 0; k < M; k++ {
		i := 0
		j := 0

		fmt.Fscanln(reader, &i, &j)

		if i == 1 {
			fmt.Fprintln(writer, cumulativeSum[j-1])
		} else {
			fmt.Fprintln(writer, cumulativeSum[j-1]-cumulativeSum[i-2])
		}
	}
}
