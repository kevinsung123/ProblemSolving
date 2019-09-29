#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n;
char map[53][53];
int ans;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int check()
{
	int max_cnt = 0;
	//행마다 열체크
	for (int i = 0;i < n;i++)
	{
		int row_cnt = 1, j = 0, rowMax = 0, colMax = 0;
		int col_cnt = 1;
		//열 체크 
		for (j = 0;j < n - 1;j++)
		{
			if (map[i][j] == map[i][j + 1])	row_cnt++;
			else row_cnt = 1;
			rowMax = max(rowMax, row_cnt);	

			if (map[j][i] == map[j + 1][i]) col_cnt++;
			else col_cnt = 1;
			colMax = max(colMax, col_cnt);
		}
		//printf("i=%d rowMax=%d colMax=%d\n", i,rowMax, colMax);
		//열 체크하면 행마다 max값 체크
		//동시에 행과 열 진행 max 값체크
		max_cnt = max(max_cnt, max(rowMax, colMax));
	}
	return max_cnt;
}
void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
void print()
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)printf("%c", map[i][j]);
		printf("\n");
	}
}
//인접한것이 가로뿐만아니라 세로도!!!
int main()
{
	scanf("%d", &n);
	int i, j;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++) scanf(" %c", &map[i][j]);
	}
	ans = -1e9;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			for (int k = 0;k < 2;k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (!map[ny][nx]) continue; //범위 벗어날때!  예외처리 오진다1!!
				swap(&map[i][j], &map[ny][nx]);
				ans = max(ans, check());
				swap(&map[i][j], &map[ny][nx]);
			}
			
		}
	}
	printf("%d", ans);

}