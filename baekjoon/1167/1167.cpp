#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int LONG_VERTEX = 0;
int MAX_DISTANCE = 0;

void dfs(vector<pair<int, int>> graph[], bool visited[], const int& currentVertex,
		 const int& currentDistance) {
	visited[currentVertex] = true;

	if (MAX_DISTANCE < currentDistance) {
		LONG_VERTEX = currentVertex;
		MAX_DISTANCE = currentDistance;
	}

	for (const auto& iter : graph[currentVertex]) {
		if (visited[iter.first] == false) {
			dfs(graph, visited, iter.first, iter.second + currentDistance);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const int MAX_LEN = 100000 + 1;

	int V = 0;
	cin >> V;

	vector<pair<int, int>> graph[MAX_LEN];
	for (int i = 0; i < V; ++i) {
		int vertex = 0;
		cin >> vertex;

		int connectedVertex = 0;
		cin >> connectedVertex;
		while (connectedVertex != -1) {
			int connectedDistance = 0;
			cin >> connectedDistance;

			graph[vertex].push_back({connectedVertex, connectedDistance});
			cin >> connectedVertex;
		}
	}

	bool visited[MAX_LEN] = {
		false,
	};

	dfs(graph, visited, 1, 0);

	memset(visited, 0x00, sizeof(visited));
	MAX_DISTANCE = 0;

	dfs(graph, visited, LONG_VERTEX, 0);

	cout << MAX_DISTANCE << "\n";

	return 0;
}
