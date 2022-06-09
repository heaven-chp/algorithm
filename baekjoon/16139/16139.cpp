#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string S = "";
	cin >> S;

	int q = 0;
	cin >> q;

	map<char, vector<int>> cumulativeSum;
	cumulativeSum.clear();

	for (int i = 0; i < (int)S.size(); ++i) {
		for (char c = 'a'; c <= 'z'; ++c) {
			if (i == 0) {
				if (c == S.at(i)) {
					cumulativeSum[c].push_back(1);
				} else {
					cumulativeSum[c].push_back(0);
				}
			} else {
				if (c == S.at(i)) {
					cumulativeSum[c].push_back(cumulativeSum[c].at(i - 1) + 1);
				} else {
					cumulativeSum[c].push_back(cumulativeSum[c].at(i - 1));
				}
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		int l = 0, r = 0;
		char c = '\0';

		cin >> c >> l >> r;

		if (l == 0) {
			cout << cumulativeSum[c].at(r) << "\n";
		} else {
			cout << cumulativeSum[c].at(r) - cumulativeSum[c].at(l - 1) << "\n";
		}
	}

	return 0;
}
