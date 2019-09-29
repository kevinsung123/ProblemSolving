#include<cstdio>
int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 1;3 * i*i - 3 * i - 1 < n;i++);
	printf("%d\n", i);
}