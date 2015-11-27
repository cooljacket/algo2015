#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long LL;
const int Limit = 30;

LL QuickPower(LL a, LL p, LL N) {
	if (p == 0)
		return 1;
	if (p == 1)
		return a % N;
	LL res = QuickPower(a, p>>1, N);
	if (p & 1 == 0)
		return (res * res) % N;
	return (a * res * res) % N;
}

bool PrimeTest(LL n) {
	LL arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	for (int t = 0; t < 10; ++t) {
		//int a = rand();
		if (QuickPower(arr[t], n-1, n) != 1)
			return false;
	}
	return true;
}

int main() {
	LL d, n;
	cin >> d >> n;

	if (d == 0) {
		cout << "000000000002" << endl;
		return 0;
	}

	for (int i = d+1; i <= 12; ++i)
		n *= 10;
	if (n % 2 == 0)
		++n;

	while (true) {
		if (PrimeTest(n)) {
			cout << n << endl;
			break;
		}
		n += 2;
	}

	return 0;
}