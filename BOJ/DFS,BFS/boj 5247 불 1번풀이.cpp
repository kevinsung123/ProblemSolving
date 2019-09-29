#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
struct F {
	int y;
	int x;
	int time;
	F(int y, int x) : y(y), x(x) {};
	F(int y, int x,int time) : y(y), x(x) ,time(time){};
};
char map[1001][1001] = {0};
int check[1001][1001];
int ans, T, H, W;
queue<F> fire;
queue<F> men;
int start[1][2];
int fstart[1][2];
bool flag;
//동 남 서 북
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void bfs() 
{
	while (1)
	{
		int size = fire.size();
		int cy, cx, cnt;
		//불처리 큐에 불사이즈만큼
		while (size--)
		{
			cy = fire.front().y;
			cx = fire.front().x;
			fire.pop();
			//같은 time  불처리
			for (int i = 0;i < 4;i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				//불이 범위를 벗어난경우
				if (ny<0 || ny>W-1  || nx<0 || nx>H-1) continue;
				
				//빈공간이거나 상원이 위치일떄
				if (map[ny][nx] == '.' || map[ny][nx]=='@')
				{
					map[ny][nx] = '*';
					fire.push(F(ny, nx));
				}

			}
		}
		//상원이 처리
		size = men.size();
		while (size--)
		{
			cy = men.front().y;
			cx = men.front().x;
			cnt = men.front().time;
			men.pop();
			for (int i = 0;i < 4;i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if (ny <0 || ny>W-1 || nx<0 || nx>H-1) //=>틀렷네..
				{
					//0이거나 끝에 도착할때 탈출성공
					flag = true;
					break;
				}
				//빈공간일떄
				if (map[ny][nx] == '.')
				{
					map[ny][nx] = '@';
					men.push(F(ny, nx, cnt + 1));
				}
			}
		}

		//불,상원이 처리 후 
		if (flag == true)
		{
			cout << cnt + 1 << "\n";
			//탈출 성공하면 초기화ㅣ
			while (!men.empty()) men.pop();
			while (!fire.empty())fire.pop();
			break;
		}
		if (men.empty())
		{
			while (!men.empty()) men.pop();
			while (!fire.empty())fire.pop();
			cout << "IMPOSSIBLE\n";
			break;
		}
	}
	return;

}


int main()
{
	cin >> T;
	while (T--)
	{
		cin >> W >> H;
		
		for (int i = 0;i < W;i++)
		{
			scanf("%s", map[i]);
			for (int j = 0; map[i][j];j++)
			{
				
				if (map[i][j] == '@')
				{
					men.push(F(i, j, 0));
			
				}
				if (map[i][j] == '*')
				{
					fire.push(F(i, j));
				}
			}
		}
		flag = false;
		bfs();
	}
}