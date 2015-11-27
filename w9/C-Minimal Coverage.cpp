// from: http://acm.timus.ru/problem.aspx?space=1&num=1303
// Author: jacket
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Seg
{
	int beg, end;
	bool operator < (const Seg& s) const {
		if (beg != s.beg)
			return beg < s.beg;
		return end > s.end;
	}
};

const int MAX = 100005;
vector<Seg> segment(MAX);

int main() {
	int M, a, b, i = 0, size;
	scanf("%d", &M);

	while (scanf("%d%d", &a, &b) == 2) {
		if (a == 0 && b == 0)
			break;
		segment[i++] = (Seg){a, b};
	}

	size = i;
	i = 0;
	sort(segment.begin(), segment.begin()+size);
	while (i < size) {
		if (segment[i].beg <= 0 && segment[i].end >= 0)
			break;
		++i;
	}

	if (i >= size) {
		printf("No solution\n");
		return 0;
	}

	// limit表示要找的区间中，必须要包含这一个点！！！初始值很明显应该是0
	int limit = 0;
	bool first = true;
	vector<Seg> v;
	while (i < size) {
		int longest = segment[i].end, index = i, j = i+1;
		while (j < size && segment[j].beg <= limit) {
			if (segment[j].end > longest) {
				longest = segment[j].end;
				index = j;
			}
			++j;
		}

		// index == i表示没能找到后续的，所以应该是 No solution的
		// 不过第一次对limit=0的情况要特殊对待一下，考虑最后面的测试案例就知道了
		if (first)
			first = false;
		else if (index == i) {
			printf("No solution\n");
			return 0;
		}
		v.push_back(segment[index]);
		limit = longest;
		i = index;
		if (limit >= M)
			break;
	}

	printf("%d\n", v.size());
	for (int j = 0; j < v.size(); ++j)
		printf("%d %d\n", v[j].beg, v[j].end);
	return 0;
}
/*
6
0 4
4 4
4 6
0 0
*/
