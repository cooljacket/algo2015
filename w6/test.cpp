#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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

void getLCS(const vector<int>& data, vector<int>& v, int i) {
	if (i == -1)
		return ;
	getLCS(data, v, prev[i]);
	v.push_back(data[i]);
}

void print(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;
}

void Init(int n) {
	for (int i = 0; i < n; ++i) {
		L[i] = 1;
		prev[i] = -1;
	}
}

int main() {
	srand(time(0));
	int n, index;
	cin >> n;
	vector<int> v(n);
	Init(n);
	for (int i = 0; i < n; ++i)
		v[i] = rand() % MAX;

	cout << "Original, the data is like: ";
	print(v);
	cout << "MAX lenght is: " << LCS(v, n, index) << endl;
	vector<int> vv;
	getLCS(v, vv, index);
	cout << "The longest subsequence is: ";
	print(vv);

	return 0;
}

git clone https://github.com/onestraw/ebook.git

footballRed.bmp