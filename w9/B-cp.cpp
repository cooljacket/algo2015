//http://acm.timus.ru/problem.aspx?space=1&num=1152
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
	int n;
	cin >> n;
	vector<int> w(n);

	for (int i = 0; i < n; ++i)
		cin >> w[i];

	int size = 1 << n;
	vector<int> dp(size, INF), sum(size, 0);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < n; ++j)
			if ((i & (1 << j)))
				sum[i] += w[j];

	dp[size-1] = 0;
	for (int i = size-1; i > 0; --i) {
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				int index[3] = {j, (j+1)%n, (j+2)%n}, x = i;
				for (int k = 0; k < 3; ++k)
					x &= (~(1 << index[k]));
				dp[x] = min(dp[x], dp[i]+sum[x]);
			}
		}
	}

	cout << dp[0] << endl;

	return 0;
}