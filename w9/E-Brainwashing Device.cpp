// ref: http://www.xuebuyuan.com/1905645.html
// source: http://acm.timus.ru/problem.aspx?num=1900

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, tmp;
	cin >> n >> k;
	vector<int> cal(n+1, 0);

	for (int i = 1; i < n; ++i)
		for (int j = 1; j <= n-i; ++j) {
			cin >> tmp;
			cal[i] += tmp;
			cal[i+j] -= tmp;
		}

	int maxN = -1, start = 0;
	for (int beg = 1; beg+k <= n; ++beg) {
		int sum = 0;
		for (int i = 0; i <= k; ++i)
			sum += cal[beg+i];
		if (sum > maxN) {
			maxN = sum;
			start = beg;
		}
	}
	printf("%d\n", maxN);

	return 0;
}