#include <stdio.h>

typedef long long LL;

bool isPrime(LL n) {
	if (n == 1)
		return false;
	for (LL i = 2; i*i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

LL solve(LL n) {
	LL ans = 1;
	/*for (LL i = 2; i*i <= n; ++i) {
		if (n % i == 0 && isPrime(i)) {
			ans *= i;
			if (i != n/i && isPrime(n/i))
				ans *= n / i;
		}
	}*/
	for (LL i = 2; i <= n; ++i)
		if (n % i == 0 && isPrime(i))
			ans *= i;
	return ans;
}

int main() {
	LL n;
	scanf("%I64d", &n);
	printf("%I64d\n", solve(n));

	return 0;
}