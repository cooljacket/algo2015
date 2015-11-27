#include <stdio.h>
#include <vector>
using namespace std;

#define mmin(a, b, c) min(min(a, b), c)
char a[1002], b[1002];

int main() {
	int n, m;
	while (scanf("%d%s%d%s", &n, &a, &m, &b) == 4) {
		vector<vector<int> > dis(n+1, vector<int>(m+1, 0));
		for (int i = 0; i <= n; ++i)
			dis[i][0] = i;
		for (int j = 0; j <= m; ++j)
			dis[0][j] = j;

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				dis[i][j] = mmin(dis[i-1][j]+1, dis[i][j-1]+1, dis[i-1][j-1]+(a[i-1]!=b[j-1]));
		printf("%d\n", dis[n][m]);
	}

	return 0;
}