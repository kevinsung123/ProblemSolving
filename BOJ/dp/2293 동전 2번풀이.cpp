#include<iostream>
#include<vector>
using namespace std;
int coin[10002];
int dp[10002];
int main()
{
	
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0;i < n;i++) scanf("%d", &coin[i]);
	dp[0] = 1;
	for (int i = 0;i < n;i++)
	{
		for (int j = 1;j <= k;j++)
		{
			if (j - coin[i] >= 0) //만들어질수있다면
			{
				dp[j] += dp[j - coin[i]];
				//printf("dp[%d]=%d  dp[%d]=%d\n", j, dp[j], j - coin[i], dp[j - coin[i]]);
			}
		}
	}
	cout<<dp[k]<<"\n";
}

//
//#include <iostream>
//#include <cstdio>
//#include <map>
//using namespace std;
//int coin[10002];
//int DP[10002];
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	for (int i = 0; i < n; i++)
//		scanf("%d", &coin[i]);
//
//	DP[0] = 1;
//
//	for (int i = 0; i < n; i++)
//		for (int j = 1; j <= m; j++)
//			if (j - coin[i] >= 0)
//			{
//				DP[j] += DP[j - coin[i]];
//				printf("dp[%d]=%d  dp[%d]=%d\n", j, DP[j], j - coin[i], DP[j - coin[i]]);
//			}
//				
//
//
//
//	cout << DP[m];
//
//	return 0;
//}
//


