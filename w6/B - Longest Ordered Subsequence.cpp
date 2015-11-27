//
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000;
int prev[MAX];
int L[MAX];

int LCS(vector<int>& v, int n, int& index) {
	for (int last = 1; last < n; ++last) {
		for (int i = 0; i < last; ++i)
			if (v[i] < v[last] && L[i] + 1 > L[last]) {
				L[last] = L[i] + 1;
				prev[last] = i;
			}
	}

	int maxN = 0;
	index = 0;
	for (int i = 0; i < n; ++i)
		if (L[i] > maxN) {
			maxN = L[i];
			index = i;
		}
	return L[index];
}

void Init(int n) {
	for (int i = 0; i < n; ++i) {
		L[i] = 1;
		prev[i] = -1;
	}
}

int main() {
	int n, index;
	cin >> n;
	vector<int> v(n);
	Init(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	cout << LCS(v, n, index) << endl;

	return 0;
}