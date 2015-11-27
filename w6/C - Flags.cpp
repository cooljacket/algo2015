#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

typedef long double LD;

int main() {
	int n;
	cin >> n;
	vector<LD> v(n+1, -1);
	v[1] = v[2] = 2;

	for (int i = 3; i <= n; ++i)
		v[i] = v[i-1] + v[i-2];

	cout << fixed << setprecision(0) << v[n] << endl;

	return 0;
}