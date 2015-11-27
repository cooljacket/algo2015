// URAL 1133
// 用C++去解方程，应该是误差的问题，wa在第12个案例上了，最后改用快速幂去二分就好了，看py的代码
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector<vector<LL> > Matrix;
Matrix Unit(2);

Matrix mul(const Matrix& a, const Matrix& b) {
	Matrix ans(a[0].size(), vector<LL>(b.size()));

	for (int i = 0; i < a[0].size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			LL sum = 0;
			for (int k = 0; k < b.size(); ++k) {
				sum += a[k][i] * b[j][k];
			}
			ans[i][j] = sum;
		}
	}

	return ans;
}

Matrix cal(int n) {
	Matrix ans(Unit);
	for (int i = 1; i < n; ++i) 
		ans = mul(ans, Unit);
	return ans;
}

int main() {
	LL i, j, n, Fi, Fj;
	cin >> i >> Fi >> j >> Fj >> n;
	Unit[0].push_back(1);	Unit[0].push_back(1);
	Unit[1].push_back(1);	Unit[1].push_back(0);

	LL X = min(min(i, j), n);
	i -= (X - 1 b 	j -= (X - 1);
	n -= (X - 1);
	
	Matrix I = cal(i);
	Matrix J = cal(j);
	LL a1 = I[0][0], b1 = I[0][1], a2 = J[0][0], b2 = J[0][1];
	LL F1 = (Fi*b2 - Fj*b1) / (a1*b2 - a2*b1);
	LL F0 = (Fi*a2 - Fj*a1) / (a2*b1 - a1*b2);

//cout << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << ' ' << F1 << ' ' << F0 << endl;
	Matrix N = cal(n);
	cout << N[0][0]*F1 + N[0][1]*F0 << endl;

	return 0;
}