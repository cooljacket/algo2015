//http://acm.timus.ru/problem.aspx?space=1&num=1203
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct conf
{
	int beg, end;
	bool operator < (const conf& c) const {
		/*if (beg != c.beg)
			return beg < c.beg;*/
		return end < c.end;
	}
};

int main() {
	int n, beg, end;
	scanf("%d", &n);
	vector<conf> v(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &beg, &end);
		v[i].beg = beg;
		v[i].end = end;
	}

	sort(v.begin(), v.end());

	int cnt = 0, last = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i].beg > last) {
			//printf("i=%d, beg=%d, end=%d, last=%d\n", i, v[i].beg, v[i].end, last);
			last = v[i].end;
			++cnt;
		}
	}
	printf("%d\n", cnt);

	return 0;
}