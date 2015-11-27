// Ref(Floyd基础知识)：http://blog.sina.com.cn/s/blog_6fbae1120100xfdd.html
// http://www.cnblogs.com/kane0526/archive/2012/11/09/2763170.html
#include <stdio.h>
#include <vector>
using namespace std;

const int MAX = 105, INF = 1e8;
typedef vector<vector<int> > Graph;

Graph dist, cp, parent;

void printPath(vector<int>& path) {
	printf("%d", path[0]);
	for (int i = 1; i < path.size(); ++i)
		printf(" %d", path[i]);
	printf("\n");
}

int Floyd(vector<int>& path) {
	int n = dist.size() - 1, minD = INF;
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i < k; ++i)
			for (int j = i+1; j < k; ++j) {
				int tmp = dist[i][j] + cp[j][k] + cp[k][i];
				if (tmp < minD) {
					minD = tmp;
					// 需要及时更新path，如果等到最后才回溯输出，会错的！
					// 因为当前这个结果与当前的parent关系有关，而下面的循环会改变parent
					path.clear();
					int key = j;
					while (key != i) {
						path.push_back(key);
						key = parent[i][key];
					}
					path.push_back(i);
					path.push_back(k);
//printf("beg=%d, end=%d, k=%d, d=%d, dij=%d, cjk=%d, cki=%d\n", i, j, k, minD, dist[i][j], cp[j][k], cp[k][i]);
				}
			}

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				if (dist[i][k]+dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					parent[i][j] = parent[k][j];
				}
			}
	}

	return minD;
}

int main() {
	int n, m, u, v, L, beg, end, last;

	while (scanf("%d", &n) == 1 && n != -1) {
		scanf("%d", &m);
		dist = parent = Graph(n+1, vector<int>(n+1, INF));
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &u, &v, &L);
			dist[u][v] = dist[v][u] = min(dist[u][v], L);
		}
		cp = dist;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				parent[i][j] = i;

		vector<int> path;
		if (Floyd(path) == INF)
			printf("No solution.\n");
		else
			printPath(path);
	}

	return 0;
}
/*
6 9
1 2 1
2 3 100
3 4 1
4 5 100
5 6 1
6 1 100
1 4 5
2 5 5
3 6 5
*/