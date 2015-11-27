// tims 1323-Classmates
// 状压dp去模拟所有可能的情况，注意不能找到一个解就退出，因为它可能不是最短的！
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Change;
const int MAX = 11;
vector<vector<int> > graph(15);
vector<bool> visited(600000);

struct Bits {
	int data[MAX], step, parent, me;
	vector<Change> v, vv;
	Bits() {
		for (int i = 1; i < MAX; ++i)
			data[i] = 0;
		step = 0;
		parent = -1;
	}

	void AllToOne(int size) {
		for (int i = 1; i < MAX; ++i)
			if (data[i] == 2)
				data[i] = 1;
	}

	bool ending(int size) const {
		for (int i = 1; i <= size; ++i)
			if (data[i] != 1)
				return false;
		return true;
	}

	void print(int size) {
		cout << "data: ";
		for (int i = size; i >= 1; --i)
			cout << data[i] << ' ' ;
		cout << endl;
	}

	int toInt(int n) {
		int base = 1, ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += base * data[i];
			base *= 3;
		}
		return ans;
	}
};
vector<Bits> vb;
map<string, int> mm;
map<int, string> mmm;

void dfs(int n) {
	if (n == -1)
		return ;
	dfs(vb[n].parent);
	if (!vb[n].vv.empty()) {
		cout << vb[n].vv.size() << endl;
		for (int i = 0; i < vb[n].vv.size(); ++i) {
			int a = vb[n].vv[i].first, b = vb[n].vv[i].second;
			cout << mmm[a] << ' ' << mmm[b] << endl;
		}
	}
}

int main() {
	int n, m;
	string a, b;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		if (mm.find(a) == mm.end()) {
			mm[a] = mm.size();
			mmm[mm[a]] = a;
		}
		if (mm.find(b) == mm.end()) {
			mm[b] = mm.size();
			mmm[mm[b]] = b;
		}
		graph[mm[a]].push_back(mm[b]);
		graph[mm[b]].push_back(mm[a]);
	}

	cin >> a;

	queue<Bits> q;
	Bits now, tmp;
	now.data[mm[a]] = 1;
	now.me = 0;
	q.push(now);
	vb.push_back(now);
	visited[now.toInt(n)] = true;
	int minN = 100000000, best = 0;

	while (!q.empty()) {
		now = q.front();	q.pop();
		bool change = false;
		for (int i = 1; i <= n; ++i) {
		//for (int i = n; i >= 1; --i) {
			if (now.data[i] == 1) {
				// 扫描结点i的所有邻边
				for (int j = 0; j < graph[i].size(); ++j) {
					int v = graph[i][j];
					if (now.data[v] == 0) {
						tmp = now;
						tmp.data[v] = 2;
						tmp.data[i] = 2;
						int key = tmp.toInt(n);
						if (!visited[key]) {
							tmp.v.push_back(make_pair(i, v));
							visited[key] = true;
							change = true;
							q.push(tmp);
						}
						change = true;
					}
				}
			}
		}
		if (!change) {
			now.AllToOne(n);
			now.vv = now.v;
			now.v.clear();
			++now.step;
			now.parent = now.me;
			vb.push_back(now);
			now.me = vb.size() - 1;
			int key = now.toInt(n);
			if (!visited[key]) {
				q.push(now);
				visited[key] = true;
			}
			if (now.ending(n)) {
				if (now.step < minN) {
					minN = now.step;
					best = now.me;
				}
				/*cout << now.step << endl;
				dfs(now.me);
				break;*/
			}
		}
	}

	cout << vb[best].step << endl;
	dfs(best);

	return 0;
}
/*
6
7
Tanya Lena
Tanya Katya
Tanya Masha
Lena Natasha
Lena Vitya
Natasha Vitya
Masha Vitya
Tanya

3
1
Tanya Lena
2
Tanya Masha
Lena Vitya
2
Vitya Natasha
Tanya Katya


4
3
A B
A C
C D
A
*/
