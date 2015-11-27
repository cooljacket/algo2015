#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int dp[1<<20];
int sum[1<<20];
int p[101];
int minz;
int main()
{
    int i,n,j,t1,t2,x;
    scanf("%d",&n);
    for(i = 0;i < n;i ++)
    {
        scanf("%d",&p[i]);
    }
    for(i = 0;i < 1<<n;i ++)
    {
        dp[i] = 10000000;
        for(j = 0;j < n;j ++)
        {
            if(i&(1<<j))
            sum[i] += p[j];
        }
    }
    dp[(1<<n)-1] = 0;
    for(i = (1<<n)-1;i >= 1;i --)
    {
        for(j = 0;j < n;j ++)
        {
            if(i&(1<<j))
            {
                x = i - (1<<j);
                printf("k=0, x=%d\n", x);
                if(j-1 < 0)
                    t1 = n-1;
                else
                    t1 = j-1;
                if(j+1 >= n)
                    t2 = 0;
                else
                    t2 = j+1;
                if(x&(1<<t1))
                    x -= 1<<t1;
                printf("k=1, x=%d\n", x);
                if(x&(1<<t2))
                    x -= 1<<t2;
                printf("k=2, x=%d\n", x);
                dp[x] = min(dp[x],dp[i]+sum[x]);
                printf("i=%d, j=%d, dp=%d\n", i, j, dp[x]);
                int a; cin >> a;
            }
        }
    }
    printf("%d\n",dp[0]);
    return 0;
}