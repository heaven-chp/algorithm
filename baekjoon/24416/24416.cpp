#include <iostream>

using namespace std;

int fibonacci_recursion(const int& n, int& callCount) {
	if (n == 1 || n == 2) {
		++callCount;
		return 1;
	}

	return fibonacci_recursion(n - 1, callCount) + fibonacci_recursion(n - 2, callCount);
}

int fibonacci_dp(const int& n, int& callCount) {
	int result[n + 1];
	result[1] = result[2] = 1;

	for (int i = 3; i <= n; ++i) {
		++callCount;
		result[i] = result[i - 1] + result[i - 2];
	}

	return result[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	int callCountRecursion = 0;
	fibonacci_recursion(n, callCountRecursion);

	int callCountDP = 0;
	fibonacci_dp(n, callCountDP);

	cout << callCountRecursion << " " << callCountDP << "\n";

	return 0;
}
