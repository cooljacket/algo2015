// URAL 1753
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double ERR = 1e-6;
double h, L, H;

double f(double x) {
	return H * x / (2.0 * sqrt(h*h + x*x)) - x;
}

int main() {
	cin >> h >> H >> L;
	double left = ERR, right = H, m1, m2;

	while (right - left > ERR) {
		m1 = (right + 2 * left) / 3;
		m2 = (2 * right + left) / 3;
		if (f(m1) > f(m2))
			right = m2;
		else
			left = m1;
	}

	cout << fixed << setprecision(6) << f(right) << endl;

	return 0;
}