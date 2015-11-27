// URAL 1528
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

int main() {
	LL n, p;
	const int MAX = 10001;
	vector<LL> f(MAX, 0), g(MAX, 0);
	g[1] = 1;
	g[2] = 2;
	for (int i = 3; i < MAX; ++i) {
		g[i] = g[i-1] * (3 - g[i-1]) + g[i-2] * g[i-2];
	}

	while (cin >> n >> p) {
		if (n == 0 && p == 0)
			break;
		f[1] = 1;

		for (int i = 2; i <= n; ++i) {
			f[i] = f[i-1] * ((1 + g[i-1]) % p);
			f[i] %= p;
		}

		cout << f[n] << endl;
	}

	return 0;
}


// 比如我们知道g[1] = 1, 然后g[n] = g[n-1] + 1, 那么就一个简单循环就好了
/*g[1] = 1;
for (int i = 2; i <= n; ++i)
	g[i] = g[i-1] + 1;*/