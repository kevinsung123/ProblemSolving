#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char map[51][51];
int ans;
int m, n;
char T[2] = { 'W','B' };

//�˻��Ϸ��� ��� ���� �ִ´�
int check(int y, int x)
{	
	int res = 1e9;
	int r = 0;
	for (int k = 0;k < 8;k++)
	{
		for (int m = 0;m < 8;m++)
		{
			if (map[y + k][x + m] != T[(k + m) % 2]) r++;
		}
	}
	//r ������� 64-r ���� ������
	res = min(r, 64 - r);
	
	return res;
}

int main()
{
	scanf("%d %d", &n,&m);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			scanf(" %c", &map[i][j]);
		}
	}
	//8*8���°��� 
	ans = 1e9;
	for (int i = 0;i <= n-8;i++)
	{
		for (int j = 0;j <= m-8;j++)
		{
			ans = min(ans, check(i, j));
		}
	}

	printf("%d\n", ans);
}