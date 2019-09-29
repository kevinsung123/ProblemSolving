#include<cstdio>
#include<algorithm>
using namespace std;
int arr[10002];
int n;
int main(void)
{

	scanf("%d", &n);
	for (int i = 0; i <n; i++)
	{
		scanf("%d", &arr[i]);
	}
	bool flag = false;
	for (int i = n-1;i >= 0;i--)
	{
		//끝에서부터 탐색 마지막 순열 체크
		if (arr[i] < arr[i - 1] || i==0) continue;
		else
		{
			int cmp = arr[i - 1];
			//뒤에있는 숫자중 큰것찾는다
			for (int k = n-1;k >= i;k--)
			{
				if (cmp < arr[k])
				{
					arr[i - 1] = arr[k];
					arr[k] = cmp;
					flag = true;
					break;
				}
			}
			sort(arr + i, arr + n);
			break;
		}
	}
	if (flag)
	{
		for(int i=0;i<n;i++) printf("%d ", arr[i]);
		printf("\n");
	}
	else puts("-1");
}