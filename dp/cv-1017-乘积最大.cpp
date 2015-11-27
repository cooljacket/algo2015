#include <iostream>
#include <string>
using namespace std;

typedef long long LL;

LL dp[50][50];

LL toDigit(string& s, int beg, int end) {
	LL ans = 0;
	for (int i = beg; i <= end; ++i) {
		ans *= 10;
		ans += LL(s[i] - '0');
	}
	return ans;
}

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;

	LL maxN = -1;
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < s.size(); ++j) {
			
		}
	}

	return 0;
}