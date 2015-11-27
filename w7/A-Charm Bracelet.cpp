#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> f(m+1, 0), w(n+1), d(n+1);
	for (int i = 1; i <= n; ++i)
		cin >> w[i] >> d[i];

	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= w[i]; --j)
			f[j] = max(f[j], f[j-w[i]]+d[i]);

	int maxN = 0;
	for (int i = 0; i <= m; ++i)
		maxN = max(maxN, f[i]);
	cout << maxN << endl;

	return 0;
}