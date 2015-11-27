#include <stdio.h>
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
	int n, tmp;
	map<int, int> pos;
	vector<Node> v;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		if (pos.find(tmp) == pos.end()) {
			v.push_back((Node){i, i, tmp});
			pos[tmp] = v.size() - 1;
		} else v[pos[tmp]].right = i;
	}

	sort(v.begin(), v.end());
	LL len = v.size(), key, fare;
	LL last_Left = v[0].right + (v[0].right - v[0].left);
	LL last_Right = v[0].right;

	for (int i = 1; i < len; ++i) {
		LL now_Left = MAX, now_Right = MAX;

		for (int j = LEFT; j <= RIGHT; ++j) {
			key = (j == LEFT) ? v[i-1].left : v[i-1].right;
			fare = (j == LEFT) ? last_Left : last_Right;

			if (v[i].right < key) {
				now_Left = min(now_Left, fare + (key-v[i].left));
				now_Right = min(now_Right, fare + (key-v[i].left) + (v[i].right-v[i].left));
			} else if (v[i].left > key) {
				now_Left = min(now_Left, fare + (v[i].right-key) + (v[i].right-v[i].left));
				now_Right = min(now_Right, fare + (v[i].right-key));
			} else {
				now_Left = min(now_Left, fare + (v[i].right-key) + (v[i].right-v[i].left));
				now_Right = min(now_Right, fare + (key-v[i].left) + (v[i].right-v[i].left));
			}
		}
		last_Left = now_Left;
		last_Right =now_Right;
	}

	printf("%lld\n", min(last_Left, last_Right) + n);

	return 0;
}