#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long LL;
struct Node
{
	int left, right, val;
	bool operator < (const Node& rhs) const {
		return val < rhs.val;
	}
};
const int LEFT = 0, RIGHT = 1;
const LL MAX = 1e15;

int main() {
	int n, tmp, index = 0;
	map<int, int> pos;
	vector<Node> v;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (pos.find(tmp) == pos.end()) {
			v.push_back((Node){i, i, tmp});
			pos[tmp] = index++;
		} else v[pos[tmp]].right = i;
	}

	sort(v.begin(), v.end());
	LL len = v.size(), key, fare;
	vector<vector<LL> > f(len, vector<LL>(2, MAX));
	f[0][LEFT] = v[0].right + (v[0].right - v[0].left);
	f[0][RIGHT] = v[0].right;

	for (int i = 1; i < len; ++i) {
		for (int j = LEFT; j <= RIGHT; ++j) {
			key = (j == LEFT) ? v[i-1].left : v[i-1].right;
			fare = f[i-1][j];

			if (v[i].right < key) {
				f[i][LEFT] = min(f[i][LEFT], fare + (key-v[i].left));
				f[i][RIGHT] = min(f[i][RIGHT], fare + (key-v[i].left) + (v[i].right-v[i].left));
			} else if (v[i].left > key) {
				f[i][LEFT] = min(f[i][LEFT], fare + (v[i].right-key) + (v[i].right-v[i].left));
				f[i][RIGHT] = min(f[i][RIGHT], fare + (v[i].right-key));
			} else {
				f[i][LEFT] = min(f[i][LEFT], fare + (v[i].right-key) + (v[i].right-v[i].left));
				f[i][RIGHT] = min(f[i][RIGHT], fare + (key-v[i].left) + (v[i].right-v[i].left));
			}
		}
	}

	cout << min(f[len-1][LEFT], f[len-1][RIGHT]) + n << endl;

	return 0;
}