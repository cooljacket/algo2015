#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	while (cin >> n && n != -1) {
		vector<int> v;
		v.push_back(n);
		while (cin >> n && n != 0)
			v.push_back(n);

		int ans = 0;
		for (int i = 0; i < v.size(); ++i) {
			for (int j = 0; j < v.size(); ++j) {
				if (i != j && v[i] == 2*v[j])
					++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}