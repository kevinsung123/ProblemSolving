#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>	
using namespace std;
typedef pair<int, int > P;
typedef struct _point {
	int l;
	int m;
	int n;
	_point(int l, int m, int n) :l(l), m(m), n(n) {};
}PO;
int L, R, C;
char map[31][31][31];
int check[31][31][31];
vector<PO> po;
//동 서 남 북 상 하 이것땜에 틀림..
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
void print()
{
	for (int i = 0;i < L;i++)
	{
		for (int m = 0;m < R;m++)
		{
			for (int n = 0;n < C;n++)
			{
				printf("%c", map[i][m][n]);

			}
			printf("\n");
		}
		printf("\n");
	}
}


void bfs()
{
	int s, y, x, des_x, des_y, des_s;
	s = po[0].l;
	y = po[0].m;
	x = po[0].n;
	des_s = po[1].l;
	des_y = po[1].m;
	des_x = po[1].n;
	check[s][y][x] = 0;
	queue<PO> Q;
	Q.push(PO(s, y, x));
	int cnt = 0;
	bool flag = false;
	while (!Q.empty())
	{
		int cs = Q.front().l;
		int cy = Q.front().m;
		int cx = Q.front().n;
		Q.pop();
		for (int i = 0;i < 6;i++)
		{
			int ns = cs + dz[i];
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			//범위 벗어난경우 벽인경우
			if (ns >= L || ns < 0 || ny >= R || ny < 0 || nx >= C || nx < 0) continue;
			if (map[ns][ny][nx] == '#') continue;
			if (check[ns][ny][nx] == -1)  //.일떄만 들어가게 해서 틀림
			{
				Q.push(PO(ns, ny, nx));
				check[ns][ny][nx] = check[cs][cy][cx] + 1;
				if (check[des_s][des_y][des_x] != -1)
				{
					printf("Escaped in  %d minute(s).\n", check[des_s][des_y][des_x]);
					flag = true;
					break;
				}
			}

		}
		if (flag) break;
	}
	if (!flag)printf("Trapped\n");
	


}


int main()
{
	while (1)
	{
		scanf("%d %d %d", &L, &R, &C);
		po.clear();
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 0;i < L;i++)
		{
			for (int m = 0;m < R;m++)
			{
				for (int n = 0;n < C;n++)
				{
					check[i][m][n] = -1;
					scanf(" %c", &map[i][m][n]);
					if (map[i][m][n] == 'S')
					{
						po.push_back(PO(i, m, n));
					}
					if (map[i][m][n] == 'E')
					{
						po.push_back(PO(i, m, n));
					}
				}
			}
		}
		bfs();

	}
}