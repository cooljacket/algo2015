#include <stdio.h>
using namespace std;

typedef long long LL;

bool isPrime(LL n) {
    if (n == 1)
        return false;
    for (LL i = 2; i*i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    LL d, n;
    scanf("%lld%lld", &d, &n);

    if (d == 0) {
        printf("000000000002\n");
        return 0;
    }

    for (int i = d+1; i <= 12; ++i)
        n *= 10;
    if (n % 2 == 0)
        ++n;

    while (true) {
        if (isPrime(n)) {
            printf("%012lld\n", n);
            break;
        }
        n += 2;
    }

    return 0;
}