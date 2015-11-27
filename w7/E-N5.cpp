//http://acm.timus.ru/problem.aspx?num=1221
/*
6
1 1 0 1 1 0
1 0 0 0 1 1
0 0 0 0 0 0
1 0 0 0 1 1
1 1 0 1 1 1 
0 1 1 1 1 1
4
1 0 0 1
0 0 0 0
0 0 0 0
1 0 0 1
0

5
No solution
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n;

	while (cin >> n && n != 0) {
		vector<vector<int> > v(105, vector<int>(105, 0)), sum = v;
		for (int r = 1; r <= n; ++r)
			for (int c = 1; c <= n; ++c) {
				cin >> v[r][c];
				sum[r][c] = sum[r][c-1] + v[r][c];
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
						for (int j = c; j < c+black; ++j)
							if (v[i][j] != 1) {
								good = false;
								break;
							}
						for (int j = c+black; j < c+black+white; ++j)
							if (v[i][j] != 0) {
								good = false;
								break;
							}
						for (int j = c+black+white; j < c+h; ++j)
							if (v[i][j] != 1) {
								good = false;
								break;
							}
					}
					if (good)
						ans = max(ans, h);
				}

		if (ans == -1)
			cout << "No solution" << endl;
		else
			cout << ans << endl;
	}

	return 0;
}