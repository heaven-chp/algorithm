#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, M = 0;
	cin >> N >> M;

	int remainder = 0;
	map<long, long> count;
	for (int i = 0; i < N; ++i) {
		int number = 0;
		cin >> number;

		remainder += number % M;
		count[remainder % M]++;
	}

	long long result = count[0];
	for (const auto& iter : count) {
		result += iter.second * (iter.second - 1) / 2;
	}

	cout << result << "\n";

	return 0;
}
