// 也可以记忆化，不用为计算的先后而烦恼╮(╯▽╰)╭
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int Matrix_chain_order(vector<int>& p) {
	int len = p.size() - 1；
	vector<vector<int> > m(n, vecotr<int>(n, INF));
	
	for (int i = 0; i < len; ++i)
		m[i][i] = 0;

	for (int L = 2; L < len; ++L)
		for (int i = 0; i+L < len; ++i)
			for (int k = i; k <= i+L; ++k) {
				m[i][i+L] = min(m[i][i+L], m[i][k] + m[k+1][i+L-1] + p[i]*p[k+1]*p[i+L+1]);
				//printf("L=%d, i=%d, k=%d, m=%d\n", L, i, k, m[i][i+L]);
			}

	return m[0][len-1];	//?
}

int main() {

	return 0;
}


#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,a[105],dp[105][105],i,j,k,l;

int main()
{
    while(~scanf("%d",&n))
    {
        for(i = 1; i<=n; i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        for(l = 2; l<n; l++)//长度从2开始枚举
        {
            for(i = 2; i+l<=n+1; i++)
            {
                j = i+l-1;
                dp[i][j] = 100000000;
                for(k = i; k<j; k++)//枚举中点
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
            }
        }
        printf("%d\n",dp[2][n]);
    }

    return 0;
}





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

    for (int L = 2; L <= n; ++L) {
        for (int beg = 1, tail=beg+L-1; tail <= n; ++beg, ++tail) {
            dp[beg][tail] = INF;
            for (int k = beg+1; k < tail; ++k)  // 枚举中间点
                dp[beg][tail] = min(dp[beg][tail], dp[beg][k]+dp[k][tail]+v[beg]*v[k]*v[tail]);
        }
    }
    printf("%d\n", dp[1][n]);

    return 0;
}