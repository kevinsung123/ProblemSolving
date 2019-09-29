#include<cstdio>
int d[1001];

int dp(int x)
{
	if (x == 0)return 1;
	if (x == 1) return 0;
	if (x == 2)	return 3;
	if (d[x] != 0) return d[x];
	int result = dp(x - 2) * 3;
	for (int i = 3;i <= x;i++)
	{
		if (i % 2 == 0)
			result += dp(x-i) * 2;
	}
	return d[x] = result;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", dp(n));
}