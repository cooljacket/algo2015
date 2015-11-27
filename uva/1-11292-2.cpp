#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX = 20005;
int dragon[MAX], loowater[MAX];

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && n != 0 && m != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &dragon[i]);
		for (int j = 0; j < m; ++j)
			scanf("%d", &loowater[j]);

		sort(dragon, dragon+n);
		sort(loowater, loowater+m);

		int di = 0, cost = 0;
		for (int i = 0; i < m; ++i) {
			if (loowater[i] >= dragon[di]) {
				cost += loowater[i];
				if (++di == n)
					break;
			}
		}
		if (di < n)
			printf("Loowater is doomed!\n");
		else
			printf("%d\n", cost);
	}
	
	return 0;
}

/*2 3
5
4
7
8
4
2 1
5
5
10
0 0*/