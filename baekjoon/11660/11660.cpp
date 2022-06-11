#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, M = 0;
	cin >> N >> M;

	int cumulativeSum[1024 + 1][1024 + 1] = {
		0,
	};

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> cumulativeSum[i][j];
			cumulativeSum[i][j] += cumulativeSum[i][j - 1];
		}
	}

	for (int i = 0; i < M; ++i) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

		cin >> x1 >> y1 >> x2 >> y2;

		int result = 0;
		for (int j = x1; j <= x2; ++j) {
			result += cumulativeSum[j][y2];
			result -= cumulativeSum[j][y1 - 1];
		}
		cout << result << "\n";
	}

	return 0;
}
