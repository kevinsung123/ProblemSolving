#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int sum[10] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
			sum[i] = arr[i];
		else
			sum[i] = sum[i - 1] + arr[i];
	}

	int n; // Äõ¸® ¼ö
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", sum[b] - sum[a - 1]);
	}

	return 0;
}


