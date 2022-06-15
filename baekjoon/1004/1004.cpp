#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 0;
	cin >> T;

	while (T--) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		int n = 0;
		cin >> n;

		int result = 0;
		for (int i = 0; i < n; ++i) {
			int cx = 0, cy = 0, r = 0;

			cin >> cx >> cy >> r;

			if (((((x1 - cx) * (x1 - cx)) + ((y1 - cy) * (y1 - cy)) < (r * r)) &&
				 (((x2 - cx) * (x2 - cx)) + ((y2 - cy) * (y2 - cy)) > (r * r))) ||
				((((x1 - cx) * (x1 - cx)) + ((y1 - cy) * (y1 - cy)) > (r * r)) &&
				 (((x2 - cx) * (x2 - cx)) + ((y2 - cy) * (y2 - cy)) < (r * r)))

			) {
				++result;
			}
		}

		cout << result << "\n";
	}

	return 0;
}
