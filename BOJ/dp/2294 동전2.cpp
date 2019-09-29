#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF = 10002;
int coin[10002];
int d[10002];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0;i < 10002;i++) d[i] = INF;  //d[0]은 1로초기화시켜야댐!!
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &coin[i]);
	}

	for (int i = 0;i < n;i++)
	{
		//만들려는 합 k가 넣은 동전보다 작은경우도있따
		if (coin[i] > k) continue;

		d[coin[i]] = 1;
		for (int j = coin[i] + 1;j <= k;j++)
		{
			//printf("d[%d]=%d ,d[%d]=%d\n", j, d[j], j - coin[i], d[j - coin[i]] +1);
			d[j] = min(d[j], d[j - coin[i]] + 1);
			//printf("d[%d]=%d \n", j, d[j] );


		}
	}
	if (d[k] == INF) d[k] = -1;
	printf("%d\n", d[k]);
}