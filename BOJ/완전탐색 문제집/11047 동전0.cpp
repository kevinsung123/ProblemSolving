#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;


//1 �׸��� �˰���

//2 ��Ʈ����ũ �ȴ�...

//3 dp �� Ǯ��

int main()
{

	int ans, cnt;
	int arr[11];
	int n, k;
	cin >> n >> k;
	for (int i = 0;i < n;i++) scanf("%d", &arr[i]);

	sort(arr, arr + n, greater<int>());
	cnt = 0, ans = 1e9;

	int tmp = k;
	for (int i = 0;i < n;i++)
	{
		if (tmp >= arr[i])
		{
			cnt += tmp / arr[i];
			tmp = tmp % arr[i];

		}
	}
	//1 greedy
	printf("%d\n", cnt);

}