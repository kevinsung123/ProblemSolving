#include<cstdio>

int main(void)
{
	int h, w, n;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &h, &w, &n);
		n--;
		printf("%d\n", (n%h + 1) * 100 + n / h + 1);

	}
}