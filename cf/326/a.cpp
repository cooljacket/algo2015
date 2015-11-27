#include <stdio.h>
#include <vector>
using namespace std;

typedef long long LL;

int main() {
	int n, a, p;
	scanf("%d", &n);
	vector<LL> A(n), P(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &p);
		A[i] = a;
		P[i] = p;
	}

	LL sum = 0;
	for (int i = 0; i < n; ++i) {
		LL now = i, m = 0;
		while (i < n && P[i] >= P[now]) {
			m += A[i];
			++i;
		}
		if (i != now)
			--i;

		sum += P[now] * m;
	}
	printf("%I64d\n", sum);

	return 0;
}