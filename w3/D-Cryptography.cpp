// URAL 1086
#include <stdio.h>
#include <vector>
using namespace std;

const int MAX = 15000;
vector<int> primes(MAX);

bool isPrime(int n) {
	for (int i = 2; i*i <= n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int k, num;
	for (int i = 2, cnt = 0; cnt < MAX; ++i) {
		if (isPrime(i))
			primes[++cnt] = i;
	}

	scanf("%d", &k);
	while (k--) {
		scanf("%d", &num);
		printf("%d\n", primes[num]);
	}

	return 0;
}