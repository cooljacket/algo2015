// Ref(Floyd基础知识)：http://blog.sina.com.cn/s/blog_6fbae1120100xfdd.html
// http://www.cnblogs.com/kane0526/archive/2012/11/09/2763170.html
#include <stdio.h>
#include <vector>
using namespace std;

const int MAX = 105, INF = 1e8;
typedef vector<vector<int> > Graph;

Graph dist, cp, parent;

void printPath(int beg, int end, int mid) {
    vector<int> path;
    int key = end;
    //printf("beg=%d, end=%d, mid=%d\n", beg, end, mid);
    while (key != beg) {
        path.push_back(key);
        //printf("key=%d\n", key);
        key = parent[beg][key];
    }
    path.push_back(beg);
    path.push_back(mid);

    printf("%d", path[0]);
    for (int i = 1; i < path.size(); ++i)
        printf(" %d", path[i]);
    printf("\n");
}

int Floyd(int& beg, int& end, int& mid) {
    int n = dist.size() - 1, minD = INF;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i < k; ++i)
            for (int j = i+1; j < k; ++j) {
                int tmp = dist[i][j] + cp[j][k] + cp[k][i];
                if (tmp < minD) {
                    minD = tmp;
                    beg = i;
                    end = j;
                    mid = k;
                    printf("beg=%d, end=%d, mid=%d\n", beg, end, mid);
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
    int n, m, u, v, L, beg, end, mid;

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
        if (Floyd(beg, end, mid) == INF)
            printf("No solution.\n");
        else
            printPath(beg, end, mid);
    }

    return 0;
}