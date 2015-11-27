// POJ 3273
#include <iostream>
#include <vector>
using namespace std;

vector<int> money(100005);
int N, M;

bool check(int limit) {
	int num = 0, sum = 0;
	for (int i = 1; i <= N; ++i) {
		if (money[i] > limit)
			return false;
		if (sum + money[i] > limit) {
			sum = 0;
			++num;
			if (num >= M)
				return false;
		}
		sum += money[i];
	}
	return true;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> money[i];

	int beg = 1, end = (N/M+1)*10000, mid;

	while (beg < end) {
		mid = (beg + end) / 2;
		if (check(mid))
			end = mid;
		else
			beg = mid + 1;
	}

	cout << beg << endl;

	return 0;
}