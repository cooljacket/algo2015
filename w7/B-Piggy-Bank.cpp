#include <stdio.h>

#define min(x, y) (x < y)?x:y

const int MAX = 10000, INF = 1e9;
int f[MAX], P[MAX], W[MAX];

int main() {
	int t, E, F, N;
	scanf("%d", &t);

	while (t--) {
		scanf("%d%d%d", &E, &F, &N);
		for (int i = 1; i <= N; ++i)
			scanf("%d%d", &P[i], &W[i]);
		F -= E;
		for (int i = 1; i <= F; ++i)
			f[i] = INF;
		f[0] = 0;
		for (int i = 1; i <= N; ++i)
			for (int w = W[i]; w <= F; ++w)
				f[w] = min(f[w], f[w-W[i]]+P[i]);
		if (f[F] == INF)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", f[F]);
	}

	return 0;
}