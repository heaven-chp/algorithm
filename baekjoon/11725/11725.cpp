#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_LEN = 100000 + 1;

void bfs(vector<int> graph[], int visited[], const int& startVertex) {

	queue<int> procedure;
	visited[startVertex] = startVertex;
	procedure.push(startVertex);

	while (procedure.empty() == false) {
		const int currentVertex = procedure.front();
		procedure.pop();

		for (const auto& iter : graph[currentVertex]) {
			if (visited[iter] == 0) {
				visited[iter] = currentVertex;
				procedure.push(iter);
			}
		}
	}
}

void run() {
	int N = 0;
	cin >> N;

	vector<int> graph[MAX_LEN];
	for (int i = 1; i < N; ++i) {
		int vertex1 = 0, vertex2 = 0;
		cin >> vertex1 >> vertex2;

		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}

	int visited[MAX_LEN] = {
		0,
	};

	bfs(graph, visited, 1);

	for (int i = 2; i <= N; ++i) {
		cout << visited[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	run();

	return 0;
}
