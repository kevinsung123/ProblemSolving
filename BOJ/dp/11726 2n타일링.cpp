#include<cstdio>
const int MOD = 10007;
int dp[1001];
int main()
{
	int n;
	scanf("%d", &n);
	dp[1] = 1, dp[2] = 2;
	for (int i = 3;i <= n;i++)
	{
		dp[i] = (dp[i - 2]+ dp[i - 1]) % MOD;
	}
	printf("%d\n", dp[n]%MOD);
}