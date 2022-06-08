#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, K = 0;
	cin >> N >> K;

	vector<int> temperatures;
	temperatures.clear();

	for (int i = 0; i < N; i++) {
		int temperature = 0;
		cin >> temperature;
		temperatures.push_back(temperature);
	}

	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += temperatures.at(i);
	}

	int result = sum;
	for (int i = K; i < N; i++) {
		sum = sum + temperatures.at(i) - temperatures.at(i - K);
		result = max(result, sum);
	}

	cout << result << "\n";

	return 0;
}
