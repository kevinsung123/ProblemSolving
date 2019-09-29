#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int DP[1003][1003];
int arr[1003][1003];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <=m;j++) scanf("%1d", &arr[i][j]);
	}

	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (arr[i][j])
			{
				DP[i][j] = min({ DP[i - 1][j],DP[i][j - 1],DP[i - 1][j - 1] } )+1;
				ans = max(DP[i][j], ans);
			}
		}
	}
	printf("%d\n", ans*ans);
}