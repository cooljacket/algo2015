// timus 1792 Hamming Code
#include <iostream>
using namespace std;

int main() {
	int a[10];
	for (int i = 1; i <= 7; ++i)
		cin >> a[i];

	int A = a[1] ^ a[3] ^ a[5] ^ a[7];
	int B = a[2] ^ a[3] ^ a[6] ^ a[7];
	int C = a[4] ^ a[5] ^ a[6] ^ a[7];
	int pos = A * 1 + B * 2 + C * 4;
	a[pos] = 1 - a[pos];

	for (int i = 1; i <= 7; ++i) {
		cout << a[i];
		cout << ((i == 7) ? '\n' : ' ');
	}

	return 0;
}