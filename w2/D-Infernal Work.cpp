// timus 1760-Infernal Work
// 自己枚举每一行，然后推公式算的，简单的组合而已
#include <iostream>
using namespace std;

typedef long long LL;

int main() {
	LL a, b, n, stop;
	cin >> a >> b >> n;

	stop = n / a;
	LL ans = 0;
	for (LL row = 0; row <= stop; ++row) {
		int beg = (row * a + 1 - 1) / b, end = (min(n, a*(row+1)) - 1) / b;
		if (beg == end)
			continue;
		LL start = (beg+1)*b - row*a, last = min(n, a*(row+1)) - end * b;
		LL tmp = start*start + last*last + (end - beg - 1) * b*b, sum = start + last + (end - beg - 1) * b;
		ans += (sum*sum - tmp) / 2;
	}

	cout << ans << endl;

	return 0;
}