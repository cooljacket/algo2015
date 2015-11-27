#include <iostream>
#include <string>
#include <vector>
using namespace std;

int toInt(char ch) {
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	if (ch >= 'A' && ch <= 'Z')
		return ch - 'A' + 10;
	return -1;
}

int main() {
	string s;
	cin >> s;
	int maxD = 0, len = 0, now;
	vector<char> v(s.size());
	for (int i = 0; i < s.size(); ++i) {
		now = toInt(s[i]);
		if (now == -1)
			continue;
		v[len++] = now;
		if (now > maxD)
			maxD = now;
	}

	if (maxD == 0) {
		cout << 2 << endl;
		return 0;
	}

	for (int k = maxD+1; k <= 36; ++k) {
		int sum = 0;
		for (int i = 0; i < len; ++i) {
			sum *= k;
			sum = (sum + v[i]) % (k-1);
		}
		if (sum == 0) {
			cout << k << endl;
			return 0;
		}
	}
	cout << "No solution." << endl;
	return 0;	
}