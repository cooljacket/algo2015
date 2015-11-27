// URAL 1196
#include <stdio.h>
#include <set>
using namespace std;

int main() {
	int n, tmp, cnt = 0;
	scanf("%d", &n);
	set<int> s;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		s.insert(tmp);
	}

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &tmp);
		if (s.find(tmp) != s.end())
			++cnt;
	}
	printf("%d\n", cnt);

	return 0;
}