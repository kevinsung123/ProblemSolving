#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100003
int dp[MAX];
int arr[MAX];

int main()
{
	int n;
	int ans = -1e9;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", &arr[i]);
	dp[0] = arr[0];
	for (int i = 1;i < n;i++) dp[i] = max(dp[i - 1] + arr[i], arr[i]);

	for (int i = 0;i < n;i++) ans = max(dp[i], ans);
	printf("%d\n", ans);
}