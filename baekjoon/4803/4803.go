package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAX_VERTEX_LEN int = 500 + 1

func countNode(graph map[int][]int, visited []bool, startVertex int) int {
	count := 1

	visited[startVertex] = true

	for _, vertex := range graph[startVertex] {
		if visited[vertex] == false {
			count += countNode(graph, visited, vertex)
		}
	}

	return count
}

func countEdge(graph map[int][]int, visited []bool, startVertex int) int {
	count := len(graph[startVertex])

	visited[startVertex] = true

	for _, vertex := range graph[startVertex] {
		if visited[vertex] == false {
			count += countEdge(graph, visited, vertex)
		}
	}

	return count
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	caseNumber := 0
	for {
		n := 0
		m := 0

		fmt.Fscanf(reader, "%d %d\n", &n, &m)
		if n == 0 && m == 0 {
			break
		}

		graph := make(map[int][]int)
		for i := 0; i < m; i++ {
			vertex1 := 0
			vertex2 := 0

			fmt.Fscanf(reader, "%d %d\n", &vertex1, &vertex2)

			graph[vertex1] = append(graph[vertex1], vertex2)
			graph[vertex2] = append(graph[vertex2], vertex1)
		}

		count := 0
		visitedEdge := make([]bool, MAX_VERTEX_LEN)
		visitedNode := make([]bool, MAX_VERTEX_LEN)
		for i := 1; i <= n; i++ {
			if visitedNode[i] == false {
				if countEdge(graph, visitedEdge, i)/2 == countNode(graph, visitedNode, i)-1 {
					count++
				}
			}
		}

		caseNumber++
		switch count {
		case 0:
			fmt.Fprintf(writer, "Case %d: No trees.\n", caseNumber)
		case 1:
			fmt.Fprintf(writer, "Case %d: There is one tree.\n", caseNumber)
		default:
			fmt.Fprintf(writer, "Case %d: A forest of %d trees.\n", caseNumber, count)
		}
	}
}
