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

		int li = 0, sum = 0;
		bool good = true;
		for (int i = 0; i < n; ++i) {
			while (li < m) {
				if (loowater[li] >= dragon[i]) {
					sum += loowater[li];
					++li;
					break;
				}
				++li;
			}
			if (li >= m && i < n-1) {
				good = false;
				break;
			}
		}
		if (good)
			printf("%d\n", sum);
		else
			printf("Loowater is doomed!\n");
	}
	
	return 0;
}