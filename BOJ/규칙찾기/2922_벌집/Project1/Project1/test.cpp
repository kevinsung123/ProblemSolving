#include<cstdio>

int main(void)
{
	int n;
	scanf("%d", &n);
	int cnt = 1;
	int m = 6;
	int check = 1;
	while (check < n)
	{
		check += cnt * m;
		cnt++;
	}
	printf("%d\n", cnt);
}