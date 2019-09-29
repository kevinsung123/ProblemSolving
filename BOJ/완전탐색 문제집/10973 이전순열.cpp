#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int arr[10001];
	for (int i = 0;i < n;i++) scanf("%d", &arr[i]);

	if (!prev_permutation(arr, arr + n))
	{
		puts("-1");
	}
	else
	{
		for (int i = 0;i < n;i++)printf("%d ", arr[i]);
		printf("\n");
	}
}