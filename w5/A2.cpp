#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> TOWER;

void print(const TOWER& t) {
	for (int i = 0; i < t.size(); ++i)
		printf("%s\n", t[i].data());
	printf("\n");
}
vector<TOWER> tt(11);
vector<bool> visited(11, false);

void doit(TOWER& t, int n) {
	if (n == 1) {
		t = TOWER(2, string(4, ' '));
		t[0][0] = ' ';
		t[0][1] = t[1][0] = '/';
		t[0][2] = t[1][3] = '\\';
		t[1][1] = t[1][2] = '_';
		tt[1] = t;
		visited[1] = true;
		return ;
	}

	if (visited[n]) {
		t = tt[n];
		return ;
	}

	doit(t, n-1);
	int row = t.size(), col = t[0].size();
	TOWER t2(row*2, string(col*2, '\0'));
	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			if (c < col/2)
				t2[r][c] = ' ';
			t2[r][c+col/2] = t[r][c];
			t2[r+row][c] = (t[r][c] == '\0') ? ' ' : t[r][c];
			t2[r+row][c+col] = t[r][c];
		}
	}
	t = t2;
	tt[n] = t;
	visited[n] = true;
}

int main() {
	int n;
	
	TOWER t;
	doit(t, 10);
	while (scanf("%d", &n) == 1 && n != 0) {
		print(tt[n]);
	}

	return 0;
}