#include<iostream>
#include<vector>
#include<cstring>
int main()
{

	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a[4][2] = { 0 };
		for (int i = 0;i < 4;i++)
		{
			scanf("%d %d", &a[i][0], &a[i][1]);
		}

		bool flag = true;
		for (int m = 0;m < 2;m++)
		{
			int cnt1 = abs(a[0][m] + a[2][m]) / 2;
			int cnt2 = abs(a[1][m] + a[2][m]) / 2;
			if (cnt1 != cnt2)
			{
				flag = false;
				break;
			}
		}

		for (int i = 0;i < 4;i++)
		{
			for (int j = 0;j < 2;j++)
			{

			}
		}
		printf("%d\n", flag);
	}
	


}