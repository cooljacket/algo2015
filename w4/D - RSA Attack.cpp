#include <iostream>
using namespace std;

int primes[400], numOfPrime = 0;
const int MAX = 32005;

bool isPrime(int n) {
	if (n == 1)
		return false;
	for (int i = 2; i*i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}
void Init() {
	for (int i = 2; i*i <= MAX; ++i) {
		if (isPrime(i))
			primes[numOfPrime++] = i;
	}
}

int getDivsor(int n, int e, int& p, int& q) {
	for (int i = 0; i < numOfPrime; ++i) {
		if (n % primes[i] == 0 && isPrime(n/primes[i])) {
			p = primes[i];
			q = n / primes[i];
			if ((p-1)*(q-1) > e)
				return (p-1)*(q-1);
		}
	}
}

int extendEuclid(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int d = extendEuclid(b, a%b, x, y);
	int xx = x;
	x = y;
	y = xx - a / b * y;
	return d;
}

int main() {
	Init();
	int t, e, n, c, p, q, x, y;
	cin >> t;
	while (t--) {
		cin >> e >> n >> c;
		int phi = getDivsor(n, e, p, q);
		extendEuclid(e, phi, x, y);
		//cout << "heihei " << e << ' ' << phi << ' ' << p << ' ' << q << endl;
		while (x < 0)
			x += phi;
		int pi = 1, d = x;
		for (int i = 0; i < d; ++i) {
			pi *= c;
			pi %= n;
		}
		cout << pi << endl;
	}
	return 0;
}