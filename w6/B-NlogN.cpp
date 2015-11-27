#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int LCS(vector<int>& v) {
	vector<int> B(v.size()+1, 0);
	int len = 1;
	B[0] = v[0];
	for (int i = 1; i < v.size(); ++i) {
		int pos = lower_bound(B.begin(), B.begin()+len, v[i]) - B.begin();
		B[pos] = v[i];
		len = max(len, pos+1);
	}
	return len;
}

int main() {
	int n, tmp;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		v[i] = tmp;
	}
	printf("%d\n", LCS(v));
	return 0;
}