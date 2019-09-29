#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 1000001
int N;
int dp[MAX + 100];

//memoization
int solve(int n)
{
	if (n == 1) return 0;
	

	if (dp[n] != -1) return dp[n];

	int res = solve(n - 1) + 1;
	if (n % 2 == 0) res=min(res, solve(n / 2) + 1);
	if (n % 3 == 0) res=min(res, solve(n / 3) + 1);
	dp[n] = res;
	return dp[n];
	

}

int main()
{
	cin >> N;
	memset(dp, -1, sizeof(dp));
	cout << solve(N);
}