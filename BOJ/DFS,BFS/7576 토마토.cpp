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
	while (1)
	{
		int qsize = tomato.size();
		
	
		while (qsize--)
		{
			cy = tomato.front().y;
			cx = tomato.front().x;
			tomato.pop();
			
			//printf("node y=%d x=%d\n", cy, cx);
			for (int k = 0;k < 4;k++)
			{
				ny = cy + dy[k];
				nx = cx + dx[k];
				if (ny<0 || ny> n-1 || nx<0 || nx> m-1) continue;
				if (map[ny][nx] == -1) continue;
				if (check[ny][nx] != -1) continue;
				
				a++;//익은 토마토 숫자
				check[ny][nx] = 1;
				tomato.push(P(ny, nx));

			}
		}
		day++;
		if (a + c == m * n)
		{
			printf("%d\n", day);
			return;
		}
		
		
	}

}


int main()
{
	//freopen("토마토.txt", "r", stdin);

		scanf("%d %d", &m, &n);
		a = 0, b = 0, c = 0;
		//if (m == 0 && n == 0) break;
		memset(check, -1, sizeof(check));
		while (!tomato.empty()) tomato.pop();

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				scanf(" %d", &map[i][j]);
				if (map[i][j] == 1)
				{
					a++;
					tomato.push(P(i, j));
					check[i][j] = 1;

				}
				if (map[i][j] == 0) b++;
				if (map[i][j] == -1) c++;
			}
		}
		//printf("처음 상태 a=%d b=%d c=%d\n", a, b, c);
		//모두 익엇을때 처음부터
		if (a + c == m * n) puts("0");
		else
		{
			bfs();
		}
	
}