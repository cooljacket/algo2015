#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX=1005;
struct Job
{
	int order,doit;
	bool operator<(const Job& j)const
	{
return doit>j.doit;
	}
};
Job jobs[MAX];
int main()
{
	int n,t=0;
	while (scanf("%d",&n)==1&&n!=0)
	{
	for (int i=0;i<n;++i)
	scanf("%d%d",&jobs[i].order,&jobs[i].doit);
	sort(jobs,jobs+n);
	int now=0,time=0;
	for (int i=0;i<n;++i){
		int tmp=now+jobs[i].order+jobs[i].doit;
		time=max(time,tmp);
		now+=obs[i].order;
	}
	printf("Case %d: %d\n",++t,time);
	}
	return 0;
}

