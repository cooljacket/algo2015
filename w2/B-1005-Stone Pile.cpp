// timus 1005-Stone Pile
#include <iostream>
using namespace std;

int dp[1000100], v[25], n, sum = 0, maxN;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}

	maxN = sum / 2;
	for (int i = 0; i < n; ++i) {
		for (int j = maxN; j >= v[i]; --j)
			dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
	}
	cout << sum - 2 * dp[maxN] << endl;

	return 0;
}