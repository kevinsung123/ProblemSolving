#include<cstdio>
typedef long long int ll;
ll d[1000001][2];
const int MOD = 1e9 + 7;

ll dp(int x)
{
	d[0][0] = 0;
	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 1;
	for (int i = 3;i <= x;i++)
	{
		d[i][1] = (d[i - 1][1] + d[i - 3][0]) % MOD;
		d[i][0] = (3 * d[i - 2][0] + 2 * d[i - 1][0] + 2*d[i][1])%MOD;
	}
	return d[x][0];
}

int main()
{
	int x;
	scanf("%d", &x);
	printf("%lld", dp(x));
	return 0;
}