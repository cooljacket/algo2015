#include <stdio.h>
#include <iostream>
using namespace std;

typedef long long LL;

int main() {
	LL t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		long long sum = 0;
		if (n % 2 == 0)
			sum += (n / 2 * (n+1));
		else
			sum += ((n+1) / 2 * n);
		for (int key = 1; key <= n; key *= 2)
			sum -= 2*key;
		cout << sum << endl;
	}
	return 0;
}