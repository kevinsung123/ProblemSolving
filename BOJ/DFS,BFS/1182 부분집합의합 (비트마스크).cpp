#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[20];
int check[20];
int main()
{
	int n, s, ans = 0;
	scanf("%d %d", &n, &s);
	for (int i = 0;i < n;i++) scanf("%d", &arr[i]);
	for (int bm = 1;bm< (1 << n);bm++)
	{
		int sum = 0;
		//각 경우에 대한 합
		for (int k = 0;k < n;k++)
		{
			if (bm & (1 << k)) sum += arr[k];
		}

		if (s == sum) ans++;
	}
	printf("%d\n", ans);
}