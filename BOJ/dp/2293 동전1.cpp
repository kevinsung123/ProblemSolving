#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	//dp[i] i원을만들수있는 모든 경우수
	int N, K, x, i, j;
	int d[10002] = { 1, };
	scanf("%d %d", &N,&K);
	for (i = 1;i <= N;i++)
	{
		scanf("%d", &x);
		for (j = 0;j <= K - x;j++)
		{
			//int a = d[j + x];
			//int b=d[j];
			d[j + x] += d[j];
			
			//printf("dp[%d]=%d  dp[%d]=%d dp[j+x]+=dp[j]=%d\n",  j + x, d[j + x],  j, d[j], a+b);
		}
	}
	printf("%d\n", d[K]);

}