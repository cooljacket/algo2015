#include <stdio.h>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n, tmp;
    scanf("%d", &n);
    vector<int> v(n+1, 0);
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        v[i] = tmp;
        dp[i][i] = 0;   // 初始化边界
    }

    for (int L = 3; L <= n; ++L) {
        for (int beg = 1, tail=beg+L-1; tail <= n; ++beg, ++tail) {
            dp[beg][tail] = INF;
            for (int k = beg+1; k < tail; ++k)  // 枚举中间点
                dp[beg][tail] = min(dp[beg][tail], dp[beg][k]+dp[k][tail]+v[beg]*v[k]*v[tail]);
        }
    }
    printf("%d\n", dp[1][n]);

    return 0;
}