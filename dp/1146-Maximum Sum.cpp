#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	int n, tmp, maxN = -1000000000;
	scanf("%d", &n);

	vector<vector<int> > sum(n+1, vector<int>(n+1, 0));
	for (int i = 1; i <= n; ++i) {
		vector<int> row(n+1, 0);
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &tmp);
			row[i] += tmp;
			sum[i][j] = sum[i-1][j] + row[i];
			//printf("i=%d, j=%d, sum=%d\n", i, j, sum[i][j]);
		}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int h = 0; h <= n-i; ++h)
				for (int w = 0; w <= n-j; ++w) {
//printf("i=%d, j=%d, i+h=%d, j+w=%d, a=%d, b=%d, c=%d, d=%d\n", i, j, i+h, j+w, sum[i+h][j+w], sum[i+h][j-1], sum[i-1][j+w], sum[i-1][j-1]);
					tmp = sum[i+h][j+w] - sum[i+h][j-1] - sum[i-1][j+w] + sum[i-1][j-1];
					maxN = max(maxN, tmp);
				}

	printf("%d\n", maxN);

	return 0;
}