#include<cstdio>
#include<algorithm>
#include<vector>
#inlcude
using namespace std;

int main(void)
{
	int C, N, num, count = 0, sum = 0, pro = 0, i = 0;

	scanf("%d", &C);
	while (C--)
	{
		scanf("%d", &N);
		double arr[1001] = { 0, };
		num = 0, sum = 0, count = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%lf",&arr[i]);    //틀린이유 데이터형식이 서로 맞지 않음..
			sum += arr[i];
		}
		double avg = (double)sum / N;
		for (i = 0;i < N;i++)
		{
			if (avg < arr[i]) count++;
		}
	
		printf("%0.3lf%%\n", 100 * (double)count / N);
	}

	return 0;

}