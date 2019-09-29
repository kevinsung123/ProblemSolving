#include<cstdio>
#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

int N;
int arr[10002];

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	bool state = 0;
	for (int j = N - 1; j >= 0; j--)
	{
		if (arr[j] > arr[j - 1] || j - 1 == 0)continue;
		else
		{
			int cmp_num = arr[j - 1];
			int max_num = 0;
			int max_index = 0;
			for (int k = j; k <= N; k++)
			{
				if (arr[k] > max_num && arr[k]<arr[j - 1])
				{
					max_num = arr[k];
					max_index = k;
				}
			}
			arr[j - 1] = max_num;
			arr[max_index] = cmp_num;
			sort(arr + j, arr + N, greater<int>());
			state = 1;
			break;
		}
	}
	if (state)	for (int i = 0; i < N; i++)printf("%d ", arr[i]);
	else printf("%d", -1);
	return 0;
}