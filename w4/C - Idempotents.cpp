#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primes;

bool isPrime(int n) {
	int end = sqrt(n);
	for (int i = 2; i <= end; ++i)
		if (n % i == 0)
			return false;
	return true;
}
 
int extendEuclid(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int d = extendEuclid(b, a%b, x, y);
	int tmpX = x;
	x = y;
	y = tmpX - a / b * y;
	return d;
}

int main() {
	int t;
	cin >> t;

	int end = 1e5;
	for (int i = 2; i < end; ++i) {
		if (isPrime(i))
			primes.push_back(i);
	}

	while (t--) {
		int p, q, n;
		cin >> n;
		for (int i = 0; i < primes.size(); ++i) {
			p = primes[i];
			if (n % p == 0) {
				q = n / p;
				break;
			}
		}
		int x, y;
		extendEuclid(p, q, x, y);
		int x1 = x < 0? (p*x + p*q):(p*x);
		extendEuclid(q, p, x, y);
		int x2 = x < 0? (q*x + p*q):(q*x);
		cout << 0 << ' ' << 1 << ' ' << min(x1, x2) << ' ' << max(x1, x2) << endl;
	}

	return 0;
}