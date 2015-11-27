//http://acm.timus.ru/problem.aspx?num=1221
// O(n^4)
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, tmp;

	while (scanf("%d", &n) == 1 && n != 0) {
		vector<vector<int> > sum(105, vector<int>(105, 0));
		for (int r = 1; r <= n; ++r)
			for (int c = 1; c <= n; ++c) {
				scanf("%d", &tmp);
				sum[r][c] = sum[r][c-1] + tmp;
			}

		int ans = -1;
		for (int r = 1; r <= n; ++r)
			for (int c = 1; c <= n; ++c)
				for (int h = 3; h <= n; h += 2) {
					if (r+h-1 > n || c+h-1 > n)
						continue;
					bool good = true;
					int half = (h + 1) / 2;
					for (int i = r; i < r+h; ++i) {
						int white = h-2*abs(half-(i-r)-1), black = (h-white)/2;
						int a1 = c, a2 = c+black, a3 = c+black+white-1, a4 = c+h-1;
	//printf("r=%d, c=%d, h=%d, i=%d, white=%d, black=%d, a1=%d, a2=%d, a3=%d, a4=%d\n", r,c,h,i,white,black,a1,a2,a3,a4);
	//printf("sum[i][a1]\n");
						if (sum[i][a2]-sum[i][a1-1] != black || 
							sum[i][a3] != sum[i][a2-1] || 
							sum[i][a4]-sum[i][a3-1] != black) {
							good = false;
							break;
						}
					}
					if (good)
						ans = max(ans, h);
				}

		if (ans == -1)
			printf("No solution\n");
		else
			printf("%d\n", ans);
	}

	return 0;
}