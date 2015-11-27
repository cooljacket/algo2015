#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

LL k_digit(int k, int n) {
	vector<LL> f1(n+2), f0(n+2);
	f1[1] = k - 1;
	f0[1] = 0;
	for (int i = 2; i <= n; ++i) {
		f1[i] = (k - 1) * (f1[i-1] + f0[i-1]);
		f0[i] = f1[i-1];
	}
	return f1[n] + f0[n];
}

int main() {
	LL k, n;
	cin >> n >> k;
	cout << k_digit(k, n) << endl;

	return 0;
}