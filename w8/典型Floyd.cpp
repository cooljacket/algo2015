// Ref(Floyd基础知识)：http://blog.sina.com.cn/s/blog_6fbae1120100xfdd.html
// 
#include <stdio.h>
#include <vector>
using namespace std;

const int MAX = 100, INF = 1e9;
typedef vector<vector<int> > Graph;

Graph dist, parent;

void Floyd() {
	int n = dist.size() - 1;
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dist[i][k]+dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k]+dist[k][j];
					parent[i][j] = k;
printf("Floyd, i=%d, j=%d, k=%d, dist[i][k]=%d, dist[k][j]=%d, parent=%d\n", 
	i, j, k, dist[i][k], dist[k][j], parent[i][j]);
				}
			}
		}
	}
}

void printPath(int beg, int end) {
	printf("beg=%d, end=%d, cost=%d\n", beg, end, dist[beg][end]);
	int key = parent[beg][end];
	vector<int> path;
	path.push_back(end);
	while (key != beg) {
		printf("beg=%d, key=%d\n", beg, key);
		path.push_back(key);
		end = key;
		key = parent[beg][end];
	}
	printf("%d", beg);
	for (int i = path.size()-1; i >= 0; --i)
		printf(" %d", path[i]);
	printf("\n");
	printf("\n");
}

int main() {
	int n, m, u, v, L;

	while (scanf("%d", &n) == 1 && n != -1) {
		scanf("%d", &m);
		dist = parent = Graph(n+1, vector<int>(n+1, INF));
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &u, &v, &L);
			dist[u][v] = dist[v][u] = min(dist[u][v], L);
		}
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				parent[i][j] = i;

		Floyd();
		for (int i = 1; i <= n; ++i)
			for (int j = i+1; j <= n; ++j)
				printPath(i, j);
	}

	return 0;
}
/*
4 3
1 2 10
1 3 20
1 4 30
-1
*/