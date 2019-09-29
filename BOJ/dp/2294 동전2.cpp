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
	for (int i = 0;i < 10002;i++) d[i] = INF;  //d[0]�� 1���ʱ�ȭ���Ѿߴ�!!
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &coin[i]);
	}

	for (int i = 0;i < n;i++)
	{
		//������� �� k�� ���� �������� ������쵵�ֵ�
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