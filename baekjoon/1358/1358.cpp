#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int W = 0, H = 0, X = 0, Y = 0, P = 0;
	cin >> W >> H >> X >> Y >> P;

	int result = 0;
	for (int i = 0; i < P; ++i) {
		int x = 0, y = 0;
		cin >> x >> y;

		if (x >= X && x <= X + W && y >= Y && y <= Y + H) {
			++result;
			continue;
		}

		if ((X - x) * (X - x) + (Y + H / 2 - y) * (Y + H / 2 - y) <= (H / 2) * (H / 2)) {
			++result;
			continue;
		}

		if ((X + W - x) * (X + W - x) + (Y + H / 2 - y) * (Y + H / 2 - y) <=
			(H / 2) * (H / 2)) {
			++result;
			continue;
		}
	}

	cout << result << "\n";

	return 0;
}
