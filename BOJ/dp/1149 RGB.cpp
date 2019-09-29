#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAX 1005
int dp[MAX][3];
int arr[MAX][3];
int N;

int main()
{
	scanf("%d", &N);
	for (int i = 0;i < N;i++)scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	
	for (int i = 1;i <= N;i++)
	{
		for (int j = 0;j < 3;j++)
			dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + arr[i - 1][j];
		
	}

	printf("%d\n", min( min(dp[N][0],dp[N][1]), dp[N][2]) );
}

