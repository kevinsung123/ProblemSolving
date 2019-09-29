#include<vector>
#include<queue>
#include<iostream>
#include<utility>
#include<functional>
using namespace std;
typedef pair<int, int> P;
int map[102][102];
int check[102][102];
int n, m;
int ans;
//µ¿,³²,¼­,ºÏ
int dx[] = {1,0,-1,0};
int dy[] = { 0,1,0,-1 };
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
			scanf("%1d", &map[i][j]);
	}
	queue<P> q;
	q.push(P(1, 1));

	for (int i = 0;i < 102;i++)for (int j = 0;j < 102;j++) check[i][j] = -1;
	check[1][1] = 1;
	int cnt = 0;
	int ans = 1e9;
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		cnt++;
		if (cy == n && cx == m)
		{
			ans = min(ans, cnt);
		}
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (map[ny][nx] == 0 || ny>n || nx>m) continue;
			if (check[ny][nx]==-1 && map[ny][nx]==1)
			{
				check[ny][nx] = check[cy][cx]+1;
				q.push(P(ny, nx));
			}
		}
		
	}
	printf("%d\n",check[n][m]);

}