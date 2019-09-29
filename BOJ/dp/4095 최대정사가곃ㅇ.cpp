#include<iostream>
#include<algorithm>
using namespace std;
int arr[1003][1003];
int DP[1003][1003];
int main()
{
	while (1)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;

		memset(arr, 0, sizeof(arr));
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= m;j++)
				scanf("%d", &arr[i][j]);
		}
		memset(DP, 0, sizeof(DP));
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (arr[i][j])
				{
					DP[i][j] = min({ DP[i - 1][j],DP[i - 1][j - 1],DP[i][j - 1] }) + 1;
					ans = max(DP[i][j], ans);
				}
			}
		}
		printf("%d\n", ans);
	}
}