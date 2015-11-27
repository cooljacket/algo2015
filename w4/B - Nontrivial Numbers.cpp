#include <stdio.h>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

double cal(int n) {
	double ans = 1.0;
	for (int i = 2; i < n; ++i)
		if (n % i == 0)
			ans += i;
	return ans / n;
}

int main() {
	int a, b, goal;
	scanf("%d%d", &a, &b);

	if (a == 1) {
		printf("%d\n", 1);
		return 0;
	}

	double low = 1e9;
	for (int i = b; i >= a; --i) {
		if (isPrime(i)) {
			printf("%d\n", i);
			return 0;
		}
		double tmp = cal(i);
		if (tmp < low) {
			low = tmp;
			goal = i;
		}
	}

	printf("%d\n", goal);
	return 0;
}