/*
7
3 4 2 2 1 4 1
-> 9

8
4 5 6 5 4 5 6 5
-> 33
*/
//http://acm.timus.ru/problem.aspx?space=1&num=1152
#include <stdio.h>
#include <vector>
using namespace std;

int data[25], minDamage = 1e9, n, sum = 0;

void dfs(int* v, int damage, int total) {
	if (total == 0) {
		minDamage = min(minDamage, damage);
		return ;
	}

	for (int beg = 0; beg < n; ++beg) {
		if (v[beg] > 0) {
			int beat = 0, index, tmp[3];
			for (int i = 0; i < 3; ++i) {
				index = (i + beg) % n;
				beat += v[index];
				tmp[i] = v[index];
				v[index] = 0;
			}
			dfs(v, damage+total-beat, total-beat);
			for (int i = 0; i < 3; ++i)
				v[(i+beg)%n] = tmp[i];
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &data[i]);
		sum += data[i];
	}

	dfs(data, 0, sum);
	printf("%d\n", minDamage);
	return 0;
}