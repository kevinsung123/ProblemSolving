#include<iostream>
#include<vector>
#include<cstdio>
#include<tuple>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct _p {
	int num;
	int y;
	int x;
	_p(int num, int y, int x) : num(num), y(y), x(x) {};
}P;
//동,서,남,북,상,하
int dy[] = {0,0,1,-1,0,0};
int dx[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};  //하로갈떄 0->-1로 했어야댐.. 실수
int L, R, C;
vector<P> start;
vector<P> dest;
char map[31][31][31];
int check[31][31][31];
tuple <int, int, int> P_S;
tuple <int, int, int> P_D;

void bfs()
{
	int s, y, x;
	int des_s, des_y, des_x;
	s = start.front().num;
	y = start.front().y;
	x = start.front().x;
	des_s = dest.front().num;
	des_y = dest.front().y;
	des_x = dest.front().x;
	//출발원소 큐에넣음
	queue<P> q;
	q.push(P(s, y, x));
	check[s][y][x] = 0;
	int level = 0;
	int time = 0;
	bool flag = false;
	while (true)
	{
		
		
		//큐에 사이즈만큼(레벨만큼 돌림)
		//printf("level=%d\n", level++);
		int qsize = q.size();
		if (qsize == 0)
		{
			printf("Trapped!\n");
			return;
		}
		for (int i = 0;i < qsize;i++)
		{
			int cs, cy, cx, ns, ny, nx;
			cs = q.front().num;
			cy = q.front().y;
			cx = q.front().x;
			if (cs == des_s && cy == des_y && des_x == cx)
			{
				printf("Escaped in %d minute(s).\n", time);
				return;
			}
			q.pop();
			//printf("node cs=%d cy=%d cx=%d\n", cs, cy, cx);
			for (int k = 0;k < 6;k++)
			{
				ns = cs + dz[k];
				ny = cy + dy[k];
				nx = cx + dx[k];

				//조건 체크 
				if (ns<0 || ns>L - 1 || ny<0 || ny>R - 1 || nx<0 || nx>C - 1) continue;
				if (map[ns][ny][nx] == '#') continue;
				if (check[ns][ny][nx] != -1) continue;


				if (check[ns][ny][nx] == -1)
				{
					check[ns][ny][nx] = check[cs][cy][cx] + 1;
					q.push(P(ns, ny, nx));
					
				}
			}
		}
		time++;
		
		//if (check[des_s][des_y][des_x] != -1) break;
	}
	
	/*if (check[des_s][des_y][des_x] != -1)printf("Escaped in %d minute(s).\n", time);
	else puts("Trapped!");*/
}
void init()
{
	start.clear();
	dest.clear();
	memset(check, -1, sizeof(check));
}

int main()
{
	while (1)
	{
		scanf("%d %d %d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0) break;
		init();
		for (int a = 0;a < L;a++)
		{
			for (int b = 0;b < R;b++)
			{
				for (int c = 0;c < C;c++)
				{
					//check[a][b][c] = -1;
					scanf(" %c", &map[a][b][c]);
					if (map[a][b][c] == 'S')
					{
						start.push_back(P(a, b, c)); P_S = make_tuple(a, b, c);
					}
					if (map[a][b][c] == 'E') 
					{
						dest.push_back(P(a, b, c));P_D = make_tuple(a, b, c);
					}
				}
			}
		}
		bfs();
	}
}