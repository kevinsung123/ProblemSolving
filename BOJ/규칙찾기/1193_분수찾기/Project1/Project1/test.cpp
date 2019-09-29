#include<cstdio>
int main(void)
{
	int x;
	int n;
	int interval;
	scanf("%d", &x);
	for (n = 0;x > (n*(n+1)) / 2;n++);
	interval = ((n*(n+1))/ 2) - x;
	//printf("n=%d,interval=%d\n", n, interval);
	if (n % 2 == 1)
		printf("%d/%d\n", 1 + interval, n - interval);
	else
		printf("%d/%d\n", n - interval, 1 + interval);

}