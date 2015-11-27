// refer: http://www.xuebuyuan.com/1950703.html
// timus 1495. One-two, One-two 2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point
{
	int level, me, oneOrTwo;
};
const int MAX = 1000001;
vector<vector<int> > preOT(3, vector<int>(MAX, -1)), preRe(3, vector<int>(MAX, -1));

void dfs(int re, int OT) {
	if (re == -1 || OT == -1)
		return ;
	dfs(preRe[OT][re], preOT[OT][re]);
	cout << OT;
}

int main() {
	int n;
	cin >> n;

	if (n == 1 || n == 2) {
		cout << n << endl;
		return 0;
	}

	vector<bool> vis(n+1, false);
	queue<Point> q;
	q.push((Point){1, 1, 1});
	q.push((Point){1, 2, 2});
	vis[1] = vis[2] = true;

	while (!q.empty()) {
		Point p(q.front());		q.pop();
		if (p.level > 30)
			break;
		for (int i = 1; i <= 2; ++i) {
			int now = (((10 % n) * p.me) % n + i) % n;
			if (!vis[now]) {
				//cout << "now: " << p.level + 1 << ' ' << p.oneOrTwo << ' ' << p.me << ' ' << i << ' ' << now << endl;
				vis[now] = true;
				preOT[i][now] = p.oneOrTwo;
				preRe[i][now] = p.me;
				q.push((Point){p.level + 1, now, i});
			}
			if (now == 0) {
				//cout << "final: " << now << ' ' << i << endl;
				dfs(now, i);
				cout << endl;
				return 0;
			}
		}
	}

	cout << "Impossible" << endl;	
	return 0;
}