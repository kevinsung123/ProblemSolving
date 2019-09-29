#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAX 1000001
int N;
int dp[MAX];

//memoization
int solve(int n)
{
	//기저 사례
	if (n <= 1) return 1;
	
	//이미 계산한경우
	if (dp[n] != 0)
		return dp[n];

	if (dp[n] == 0)
	{
		int res = solve(n - 1) + 1;
		if (n % 2 == 0)  res = min(res, solve(n / 2) + 1);
		if (n % 3 == 0)  res = min(res, solve(n / 3) + 1);
		dp[n] = res;
		return res;
	}
}

//tabulation
int mincnt(int n)
{
	for (int i = 2;i <= N;i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	return dp[n];
}
int main()
{
	scanf("%d", &N);
	dp[1] = 0, dp[2] = 1, dp[3] = 1;
	printf("%d\n", solve(N));
}