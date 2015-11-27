//http://acm.timus.ru/problem.aspx?num=1039
//记忆化搜索比较简单写，白痴化操作，不用去管它的拓扑序
#include <stdio.h>
#include <vector>
using namespace std;

typedef vector<vector<int> > Graph;
const int INF = 1e8, MAX = 6005;
int happy[MAX];
Graph g(MAX);
vector<vector<int> > dp(MAX, vector<int>(2, INF));

void cal(int key) {
	if (dp[key][0] != INF)
		return ;
	dp[key][1] = happy[key];
	dp[key][0] = 0;
	
	for (int i = 0; i < g[key].size(); ++i) {
		int v = g[key][i];
		if (dp[v][0] == INF)
			cal(v);
		dp[key][0] += max(dp[v][0], dp[v][1]);
		dp[key][1] += dp[v][0];
	}
	//printf("IN, key=%d, 0=%d, 1=%d\n", key, dp[key][0], dp[key][1]);
}

int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &happy[i]);

	while (scanf("%d%d", &a, &b) == 2) {
		if (a == 0 && b == 0)
			break;
		g[b].push_back(a);
	}
	
	int maxN = -1e9;
	for (int i = 1; i <= n; ++i) {
		cal(i);
		maxN = max(maxN, max(dp[i][0], dp[i][1]));
		//printf("i=%d, 0=%d, 1=%d\n", i, dp[i][0], dp[i][1]);
	}
	printf("%d\n", maxN);

	return 0;
}