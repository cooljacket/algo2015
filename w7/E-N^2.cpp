//http://acm.timus.ru/problem.aspx?num=1221
// O(n^4)
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, tmp;

	while (scanf("%d", &n) == 1 && n != 0) {
		vector<vector<int> > v(102, vector<int>(102, 0)), f1 = v, f2 = v, f3 = v, f4 = v;
		for (int r = 1; r <= n; ++r)
			for (int c = 1; c <= n; ++c) {
				scanf("%d", &tmp);
				v[r][c] = tmp;
			}

		int ans = 1;
		for (int r = 1; r <= n; ++r)
			for (int c = 1; c <= n; ++c) {
				if (v[r][c] == 0) {
					if (f1[r][c] == 0)
						f1[r][c] = 1;
					if (f2[r][c] == 0)
						f2[r][c] = 1;
					if (f3[r][c] == 0)
						f3[r][c] = 1;
					if (f4[r][c] == 0)
						f4[r][c] = 1;
				}
				if (f1[r-1][c] == f1[r][c-1] && f1[r-f1[r-1][c]][c-f1[r-1][c]] == 1)
					f1[r][c] = f1[r-1][c] + 1;
				if (f2[r+1][c] == f2[r][c-1] && f2[r+f2[r+1][c]][c-f2[r+1][c]] == 1)
					f2[r][c] = f2[r+1][c] + 1;
				if (f3[r-1][c] == f3[r][c+1] && f3[r-f3[r-1][c]][c+f3[r-1][c]] == 1)
					f3[r][c] = f3[r-1][c] + 1;
				if (f4[r+1][c] == f4[r][c+1] && f4[r+f4[r+1][c]][c+f4[r+1][c]] == 1)
					f4[r][c] = f4[r+1][c] + 1;
			}

				for (int r = 1; r <= n; ++r)
					for (int c = 1; c <= n; ++c) {
						if (f1[r-1][c] == f1[r][c-1] && f1[r-f1[r-1][c]][c-f1[r-1][c]] == 1)
							f1[r][c] = f1[r-1][c] + 1;
						if (f2[r+1][c] == f2[r][c-1] && f2[r+f2[r+1][c]][c-f2[r+1][c]] == 1)
							f2[r][c] = f2[r+1][c] + 1;
						if (f3[r-1][c] == f3[r][c+1] && f3[r-f3[r-1][c]][c+f3[r-1][c]] == 1)
							f3[r][c] = f3[r-1][c] + 1;
						if (f4[r+1][c] == f4[r][c+1] && f4[r+f4[r+1][c]][c+f4[r+1][c]] == 1)
							f4[r][c] = f4[r+1][c] + 1;

		printf("r=%d, c=%d, f1=%d, f2=%d, f3=%d, f4=%d\n", r, c, f1[r][c], f2[r][c], f3[r][c], f4[r][c]);
						if (f1[r][c] == f2[r][c] && f2[r][c] == f3[r][c] && f3[r][c] == f4[r][c])
							ans = max(ans, f1[r][c]);
					}

				

		if (ans == 1)
			printf("No solution\n");
		else
			printf("%d\n", ans);
	}

	return 0;
}