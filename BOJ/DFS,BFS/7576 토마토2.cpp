#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
typedef struct _p
{
	int y;
	int x;
	_p(int y, int x) : y(y), x(x) {};
}P;
int a, b, c;//1, 0,-1
int n, m;
int map[1002][1002];
int check[1002][1002];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<P> to;
queue <P>tomato;
void bfs()
{
	int ny, nx, cy, cx, day = 0;
	while (!tomato.empty())
	{
		int qsize = tomato.size();
		//printf("level=%d\n", day);
		while (qsize--)
		{
			cy = tomato.front().y;
			cx = tomato.front().x;
			tomato.pop();
			//printf("node cy=%d cx=%d\n", cy, cx);
			for (int k = 0;k < 4;k++)
			{
				ny = cy + dy[k];
				nx = cx + dx[k];
				if (ny<0 || ny> n - 1 || nx<0 || nx> m - 1) continue;
				if (map[ny][nx] == -1) continue;
				if (check[ny][nx] != -1) continue;
				if (map[ny][nx] == 0)
				{
					check[ny][nx] = 1;
					tomato.push(P(ny, nx));
					map[ny][nx] = 1;

				}
			

			}
		}
		day++;
	}
	//익지않은 토마토가 있을때
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (map[i][j] == 0)
			{
				puts("-1");
				return;
			}
		}
	}
	//다익엇을떄
	//마지막 처리하고 day++이므로 하루 빼준다
	printf("%d\n", day-1);
}


int main()
{
	

	scanf("%d %d", &m, &n);
	memset(check, -1, sizeof(check));
	bool flag = true;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			scanf(" %d", &map[i][j]);
			if (map[i][j] == 1)
			{
				
				tomato.push(P(i, j));

			}
			if (map[i][j] == 0)
			{
				flag = false;
			}
		
		}
	}
	//모두 익엇을때 처음부터
	if (flag) puts("0");
	else
	{
		bfs();
	}

}