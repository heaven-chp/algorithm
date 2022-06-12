#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int K = 0;
	cin >> K;

	int LEN = 6;
	int len[LEN];

	int bigWidth = 0;
	int bigVertical = 0;
	for (int i = 0; i < LEN; ++i) {
		int temp = 0;
		cin >> temp;
		cin >> len[i];

		if (i % 2 == 0) {
			bigWidth = max(bigWidth, len[i]);
		} else {
			bigVertical = max(bigVertical, len[i]);
		}
	}

	int smallWidth = 0;
	int smallVertical = 0;
	for (int i = 0; i < LEN; ++i) {
		if (i % 2 == 0 && (len[(i + 5) % LEN] + len[(i + 1) % LEN] == bigVertical)) {
			smallWidth = len[i];
		} else if (i % 2 && (len[(i + 5) % LEN] + len[(i + 1) % LEN] == bigWidth)) {
			smallVertical = len[i];
		}
	}

	cout << ((bigWidth * bigVertical) - (smallWidth * smallVertical)) * K << "\n";

	return 0;
}
