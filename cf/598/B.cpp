#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;

void change(int beg, int end, int n) {
	int len = end - beg + 1;
	n %= len;
	string cp(s.substr(beg, len));
	//cout << "CP: " << cp << endl;
	for (int i = beg; i <= end; ++i) {
		//cout << "i=" << i << ' ' << (i-beg+n) << ' ' << s[(i-beg+n)%len+beg] << ' ' << cp[i-beg] << endl;
		s[(i-beg+n)%len + beg] = cp[i-beg];
	}
}

int main() {
	cin >> s;
	int m, a, b, n;
	cin >> m;

	while (m--) {
		cin >> a >> b >> n;
		change(a-1, b-1, n);
		//cout << s << endl;
	}

	cout << s << endl;
	
	return 0;
}