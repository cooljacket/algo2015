#include <iostream>
using namespace std;

typedef long double LD;
const int MAX = 2005;
LD f[MAX];

int main() {
	// 预处理f数组
	f[0] = 0, f[1] = 1;
	for (int i = 2; i < MAX; ++i)
		f[i] = f[i-1] + f[i-2];

	int i, j, n;
	LD Fi, Fj, Fn, Fii;
	cin >> i >> Fi >> j >> Fj >> n;

	if (i > j) {
		swap(i, j);
		swap(Fi, Fj);
	}

	// 因为数组的下标应该是非负的
	i += 1000, j += 1000, n += 1000;

	// 求出F(i+1)
	Fii = (j - i == 1) ? Fj : ((Fj - f[j-i-1]*Fi) / f[j-i]);

	if (n == i)
		Fn = Fi;
	else if (n - i == 1)
		Fn = Fii;
	else if (n - i > 1) {
		// 注意不能直接用公式：Fn = f[n-i]*Fii + f[n-i-1]*Fi，中间的乘法可能会爆
		for (int index = i+2; index <= n; ++index) {
			Fn = Fii + Fi;
			Fi = Fii;
			Fii = Fn;
		}
	}
	else {
		for (int index=i-1; index >= n; --index) {
			Fn = Fii - Fi;
			Fii = Fi;
			Fi = Fn;
		}
	}

	cout << (int)Fn << endl;

	return 0;
}