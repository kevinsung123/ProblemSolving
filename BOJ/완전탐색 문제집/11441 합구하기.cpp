#include<iostream>
#include<vector>
using namespace std;
int sum[100001];
int arr[100001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++)scanf("%d", &arr[i]);

	for (int i = 1;i <= n;i++)
	{
		if (i == 1) sum[i] = arr[i];
		else
			sum[i] = sum[i - 1] + arr[i];
	}
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int i, j;
		scanf("%d %d", &i, &j);
		printf("%d\n", sum[j] - sum[i-1]);

	}
}