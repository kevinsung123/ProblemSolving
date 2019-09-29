#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct _p {
	int y;
	int x;
	int tm;
	_p(int y, int x) : y(y), x(x) {};
	_p(int y, int x, int tm) : y(y), x(x), tm(tm) {};
}P;
char map[51][51];
int check[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int r, c;
vector<P> start;
vector<P> des;
queue<P> water;
queue<P> man;

void init()
{
	start.clear();
	des.clear();

	memset(check, -1, sizeof(check));
	while (!water.empty()) water.pop();
	while (!man.empty())man.pop();
}

void bfs()
{
	int cy, cx, ny, nx;
	int ctm = 0;

	bool flag = false;
	int level = 0;
	while (1)
	{
		//printf("level =%d\n", level);
		int w_size = water.size();
		while (w_size--)
		{
			cy = water.front().y;
			cx = water.front().x;
			water.pop();
			//printf("water node cy=%d cx=%d\n", cy, cx);
			for (int k = 0;k < 4;k++)
			{
				ny = cy + dy[k];
				nx = cx + dx[k];
				if (ny<0 || ny>r - 1 || nx<0 || nx>c - 1) continue;
				if (map[ny][nx] == 'X') continue;
				if (map[ny][nx] == 'D') continue;
				//상범이가 있거나 방문안했으면 퍼짐
				//조건을 잘 읽자 물도 비버의소굴을 통과할수없다!!
				if (check[ny][nx] == -1 || check[ny][nx] == 1)
				{
					map[ny][nx] = '*';
					water.push(P(ny, nx));
					check[ny][nx] = 2;
				}

			}
		}
		int m_size = man.size();
		while (m_size--)
		{
			cy = man.front().y;
			cx = man.front().x;
			ctm = man.front().tm;
			man.pop();
			//printf("man node cy=%d cx=%d ctime=%d\n", cy, cx,ctm);
			if (map[cy][cx] == 'D')
			{
				flag = true; break;
			}
			for (int k = 0;k < 4;k++)
			{
				ny = cy + dy[k];
				nx = cx + dx[k];
				if (ny<0 || ny>r - 1 || nx<0 || nx>c - 1) continue;
				if (map[ny][nx] == 'X' || map[ny][nx] == '*') continue;
				if (check[ny][nx] == -1)
				{
					man.push(P(ny, nx, ctm + 1));
					check[ny][nx] = 1;
				}


			}

		}
		//정답 체크
		if (flag)
		{
			printf("%d\n", level);
			break;
		}
		if (man.empty())
		{
			puts("KAKTUS");break;
		}
		//한 level 끝나고 증가
		level++;
	}
}
int main()
{
	//freopen("탈출.txt", "r", stdin);
	int t;
	//scanf("%d", &t);
	//while (t--)

	scanf("%d %d", &r, &c);
	init();
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S')
			{
				//start.push_back(P(i, j));
				man.push(P(i, j, 0));
				check[i][j] = 1;

			}
			if (map[i][j] == '*')
			{
				water.push(P(i, j));
				check[i][j] = 2;
			}


		}
	}
	bfs();

}