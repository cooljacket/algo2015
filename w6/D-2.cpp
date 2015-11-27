#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

LL k_digit(int k, int n) {
	vector<LL> f(n+2, 0);
	f[1] = k - 1;
	for (int i = 2; i <= n; ++i)
		f[i] = (k - 1) * (f[i-1] + f[i-2]);
	return f[n] + f[n-1];
}

int main() {
	LL k, n;
	cin >> n >> k;
	cout << k_digit(k, n) << endl;

	return 0;
}


2588920524
