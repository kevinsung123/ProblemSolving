#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
typedef struct _p {
	int y;
	int x;
	bool flag;
	_p(int y, int x, bool flag) : y(y), x(x), flag(flag) {};
}P;
using namespace std;
int map[1001][1001];
int check[2][1001][1001];
int m, n;
int ans;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs()
{
	queue<P> q;
	q.push(P(0, 0, false));
	int cy, cx, ny, nx;
	bool reach = false;
	bool crashed;
	int time = 1;
	check[0][0][0] = 1;
	check[1][0][0] = 1;
	while (1)
	{
		int qsize = q.size();
		//level 만큼 돌린다
		if (qsize == 0)
		{
			puts("-1");
			return;
		}
		//printf("level=%d\n", time);
		for (int i = 0;i < qsize;i++)
		{
			cy = q.front().y;
			cx = q.front().x;
			crashed = q.front().flag; //현재좌표에대한 벽부순여부
			q.pop();
			if (cy == n - 1 && cx == m - 1)
			{
				
				//printf("cy=%d cx=%d  result=%d\n", cy,cx,time);
				//reach = true;
				//break;
				printf("%d\n", time);
				return;
			}
			//printf("node crashed=%d  y=%d x=%d time=%d \n", crashed,cy, cx, time);
			for (int k = 0;k < 4;k++)
			{
				ny = cy + dy[k];
				nx = cx + dx[k];
				if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1) continue;
				//printf("check[%d][%d][%d]=%d\n",crashed,ny,nx ,check[crashed][ny][nx]);
				if (check[crashed][ny][nx]!=-1) continue;


				//벽이고 아직 벽 안부순경우 
				if (map[ny][nx] == 1 && crashed==false)
				{
					if (crashed) continue;
					check[1][ny][nx]= 1;
					q.push(P(ny, nx, true));
				}
				else if(map[ny][nx]==0) {  //조건이 정교하지못해서 틀림
					check[crashed][ny][nx] = 1;
					q.push(P(ny, nx, crashed));
				}



			}
		}
		//if (reach) break;
		time++;
	}

	//if (check[0][n - 1][m - 1] || check[1][n - 1][m - 1]) printf("%d\n", time);

}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			scanf(" %1d", &map[i][j]);
		}
	}
	ans = 1e9;
	memset(check, -1, sizeof(check));
	bfs();

}
