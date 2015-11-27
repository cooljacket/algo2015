//http://acm.timus.ru/problem.aspx?num=1167
// 想一下为何初始条件只是f[0][0] = 0
#include <stdio.h>
#include <vector>
using namespace std;
#define min(a, b) (a < b)?a:b

const int MAX = 502, BLACK = 1, WHITE = 0, INF = 1e9;
int B[MAX], W[MAX];
vector<vector<int> > f(MAX, vector<int>(MAX, INF));

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
		//printf("i=%d, Bi=%d, Wi=%d\n", i, B[i], W[i]);
	}

	f[0][0] = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i && j <= K; ++j)
			for (int k = 1; k <= i-(j-1); ++k)
				f[i][j] = min(f[i][j], f[i-k][j-1] + (B[i]-B[i-k])*(W[i]-W[i-k]));
	printf("%d\n", f[N][K]);

	return 0;
}