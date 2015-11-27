#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = asin(1)*2.0;

double calAngle(double x, double y) {
	double ans = atan(abs(y)/abs(x));
	if (x >= 0 && y >= 0)
		return ans;
	else if (x < 0 && y >= 0)
		return ans + PI;
	else if (x < 0 && y < 0)
		return ans + PI*2;
	else return ans + PI*3;
}

double diff(double a1, double a2) {
	if (abs(a1 - a2) > PI)
		return abs(a1 - a2) - PI;
	return abs(a1 - a2);
}

struct Node
{
	double x, y;
	int index;
	bool operator < (const Node& rhs) const {
		if (x != rhs.x)
			return x < rhs.x;
		return y < rhs.y;
	}
};

int main() {
	int n, a, b;
	scanf("%d", &n);

	vector<Node> v(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		double len = sqrt(a*a + b*b);
		v[i].x = a * 1.0 / len;
		v[i].y = b * 1.0 / len;
		v[i].index = i + 1;
	}

	sort(v.begin(), v.end());
	/*for (int i = 0; i < n; ++i)
		printf("%lf %lf\n", v[i].first, v[i].second);*/
	
	double minA = 100.0, last = calAngle(v[0].x, v[0].y), now;
	a = 0, b = 1;
	for (int i = 0; i < n; ++i) {
		int key = (i + 1) % n;
		now = diff(calAngle(v[key].x, v[key].y), last);
		if (now < minA) {
			minA = now;
			a = v[i].index;
			b = v[key].index;
		}
		printf("Now: i=%d, last=%lf, x=%lf, y=%lf, index=%d\n", i, last, v[i].x, v[i].y, v[i].index);
		printf("Now: now=%lf, x=%lf, y=%lf, index=%d\n\n", now, v[key].x, v[key].y, v[key].index);
		last = now;
	}

	printf("%d %d\n", a, b);

	return 0;
}