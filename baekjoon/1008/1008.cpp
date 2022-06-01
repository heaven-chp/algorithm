#include <iomanip>
#include <iostream>

using namespace std;

int main(void) {
	double a = 0, b = 0;
	cin >> a >> b;

	cout.precision(12);
	cout << fixed;
	cout << a / b << endl;

	return 0;
}
