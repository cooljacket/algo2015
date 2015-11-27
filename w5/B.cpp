#include <stdio.h>
#include <vector>
using namespace std;

vector<int> cnt(10001);
vector<int> ans(10001);

void doit(int left, int right) {
    if (left == right)
        return ;
    vector<int> tmp(ans);
    int index = left;
    for (int i = left; i <= right; i += 2, ++index)
        ans[index] = tmp[i];
    for (int i = left+1; i <= right; i += 2, ++index)
        ans[index] = tmp[i];
    doit(left, (left+right)/2);
    doit((left+right)/2 + 1, right);
}

int main() {
    int n;
    for (int i = 0; i < cnt.size(); ++i)
        cnt[i] = i;

    while (scanf("%d", &n) == 1 && n != 0) {
        ans = cnt;
        doit(0, n-1);
        printf("%d:", n);
        for (int i = 0; i < n; ++i)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}