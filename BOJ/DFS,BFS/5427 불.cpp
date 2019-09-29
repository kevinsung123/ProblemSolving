#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct _p {
	int y;
	int x;
	_p(int y, int x) :y(y), x(x) {};
}P;
int t, w, h;
char map[1002][1002];
int check[1002][1002];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<P> start;
vector<P> f_start;
void bfs()
{
	//사람 큐에 넣음 
	int s_y, s_x, f_y, f_x;
	s_y = start[0].y;
	s_x = start[0].x;
	queue<P> man;
	check[s_y][s_x] = 1;
	man.push(P(s_y, s_x));

	//불 큐에 넣음  불의 위치가 여러개일수도있따!!
	queue<P> fire;
	for (int i = 0;i < f_start.size();i++)
	{
		int y = f_start[i].y;
		int x = f_start[i].x;
		fire.push(P(y, x));
		check[y][x] = 2;
	}




	int time = 0;
	int level = 0;
	bool flag = false;
	while (1)
	{
		int f_size = fire.size();
		int cy, cx, ny, nx;

		if (fire.size() == 0 && man.size() == 0)
		{
			puts("IMPOSSIBLE"); return;
		}
		//printf("level =%d\n", level);
		//불처리
		for (int i = 0;i < f_size;i++)
		{
			cy = fire.front().y;
			cx = fire.front().x;
			fire.pop();
			//printf("fire node y=%d x=%d\n", cy, cx);
			for (int k = 0;k < 4;k++)
			{
				ny = cy + dy[k];
				nx = cx + dx[k];
				if (ny<0 || ny>h - 1 || nx<0 || nx>w - 1) continue;
				if (map[ny][nx] == '#') continue;

				//방문하지않았거나 상범이가 있는곳 불번짐!!
				if (check[ny][nx] == -1 || check[ny][nx] == 1)
				{
					fire.push(P(ny, nx));
					map[ny][nx] = '*';// 불이 번진다
					check[ny][nx] = 2;
				}

			}
		}

		int m_size = man.size();
		for (int i = 0;i < m_size;i++)
		{
			cy = man.front().y;
			cx = man.front().x;
			man.pop();
			//printf("man node y=%d x=%d\n", cy, cx);
			//탈출조건
			if (cy == h - 1 || cx == w - 1 || cy == 0 || cx == 0)
			{
				printf("%d\n", time + 1);
				return;
			}
			for (int k = 0;k < 4;k++)
			{
				ny = cy + dy[k];
				nx = cx + dx[k];
				if (ny<0 || ny>h - 1 || nx<0 || nx>w - 1) continue;
				if (map[ny][nx] == '#' || map[ny][nx] == '*') continue;
				if (check[ny][nx] != -1) continue;

				map[ny][nx] = '@';
				man.push(P(ny, nx));
				check[ny][nx] = 1;

			}
		}
		level++;
		time++;

	}
}
void init()
{
	start.clear();
	f_start.clear();
	memset(check, -1, sizeof(check));
	//fill(check, check+sizeof(check), -1);
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		//w 너비 h 높이
		scanf("%d %d", &w, &h);
		init();
		for (int i = 0;i < h;i++)
		{
			for (int j = 0;j < w;j++)
			{
				scanf(" %c", &map[i][j]);
				if (map[i][j] == '@') start.push_back(P(i, j));
				if (map[i][j] == '*') f_start.push_back(P(i, j));
			}
		}
		bfs();
	}
}