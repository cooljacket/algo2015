// URAL 1654
// 手动模拟栈就好了，又快，代码又短！
#include <stdio.h>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[200001];

int main() {
	gets(s);

	int len = strlen(s), top = 0;
	for (int i = 1; i < len; ++i) {
		if (!isalnum(s[i]))
			continue;
		if (s[i] == s[top])
			--top;
		else
			s[++top] = s[i];
	}
	s[top+1] = '\0';
	printf("%s\n", s);

	return 0;
}