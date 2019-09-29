#include<cstdio>
#include<cstdlib>
int main()
{
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 5;i <= n;i *= 5)
		cnt += n / i;
	printf("%d\n", cnt);
}