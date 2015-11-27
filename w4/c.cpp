#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
#include<map>
using namespace std;
#define N 35000
#define LL long long
int p[N],g;
map<int,int>f;
void init()
{
    int i,j;
    for(i = 2; i <= 32000 ; i++)
    if(!f[i])
    {
        for(j = i+i ; j < N ; j+=i)
        f[j] = 1;
    }
    for(i = 2; i < N ; i++)
    if(!f[i])
    p[++g] = i;
}
void exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;y=0;
        return ;
    }
    exgcd(b,a%b,x,y);
    int t = x;
    x = y;
    y = t-a/b*y;
}
int main()
{
    int k,n,x,y,a,b,i;
    init();
    cin>>k;
    while(k--)
    {
        cin>>n;
        int tx = sqrt(n*1.0);
        for(i = 1; i <= g ; i++)
        {
            int o = p[i];
            if(n%o==0)
            {
                a = o;
                b = n/o;
                break;
            }
            if(o>tx) break;
        }
        exgcd(a,b,x,y);
        int x1 = x<0? a*x+a*b:a*x;
        cout << "c1: " << a << ' ' << b << ' ' << x << ' ' << y << ' ' << x1 << endl;
        exgcd(b,a,x,y);
        int x2 = x<0? b*x+b*a:b*x;
        cout << "c1: " << a << ' ' << b << ' ' << x << ' ' << y << ' ' << x1 << endl;
        printf("0 1 %d %d\n",min(x1,x2),max(x1,x2));
    }
    return 0;
}