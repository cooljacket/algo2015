//http://acm.timus.ru/problem.aspx?num=1167
// 想一下为何初始条件只是f[0][0] = 0
#include <stdio.h>
#include <vector>
using namespace std;
#define min(a, b) (a < b)?a:b

const int MAX = 502, BLACK = 1, WHITE = 0, INF = 1e9;
int B[MAX], W[MAX];
vector<int> f(MAX, INF);

int main() {
	int N, K, color;
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &color);
		if (color == BLACK) {
			B[i] = B[i-1] + 1;
			W[i] = W[i-1];
		} else {
			B[i] = B[i-1];
			W[i] = W[i-1] + 1;
		}
	}

	f[0] = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = min(i, K); j > 0; --j)
			for (int k = 1; k <= i-(j-1); ++k) {
				f[i] = min(f[i], f[i-k] + (B[i]-B[i-k])*(W[i]-W[i-k]));
				printf("j=%d, i=%d, k=%d, f=%d\n", j, i, k, f[i]);
			}
	printf("%d\n", f[N]);

	return 0;
}
/*
6 3
1
1
0
1
0
1
*/