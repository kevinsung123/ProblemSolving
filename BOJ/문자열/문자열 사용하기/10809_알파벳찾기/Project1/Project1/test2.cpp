#include<cstdio>
char c;
int a[26], i;
int main() {
	while (~scanf(" %c", &c)) a[c - 'a'] ? ++i : a[c - 'a'] = ++i;
	for (int i = 0; i < 26; i++) printf("%d ", a[i] - 1);
	return 0;
}