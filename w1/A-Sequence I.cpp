// URAL 1910
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, tmp;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	int maxN = v[1] + v[2] + v[3], maxI = 2;
	for (int mid = 2; mid <= n-1; ++mid) {
		tmp = v[mid-1] + v[mid] + v[mid+1];
		if (tmp > maxN) {
			maxN = tmp;
			maxI = mid;
		}
	}

	cout << maxN << ' ' << maxI << endl;

	return 0;
}