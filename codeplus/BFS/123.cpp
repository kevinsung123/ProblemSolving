#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAX 1e9

int W, H, ans;
char map[101][101];
int check[101][101];
// 0 : 동 1: 서 2: 북 3: 남
int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };
vector<pair<int, int>> C;
typedef struct dir {
	int y;
	int x;
	int dir;
	int cnt;

}Dir;

void bfs(int y, int x)
{
	//처음 시작바문 
	check[y][x] = 0;

	//queue<Dir> q;
	queue < pair<pair<int,int>, pair<int,int> >> q;

	//처음 좌표기준으로 4방향을 넣음
	for (int i = 0; i < 4; i++)
	{

		q.push({ i,{y,x} });
	}

	while (!q.empty())
	{

		int y = q.front().second.first;
		int x = q.front().second.second;
		int dir = q.front().first;
		int cnt = check[y][x];
		q.pop();


		//4방향 탐색
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nCnt = cnt;


			//빈칸인경우, 맵안, 방문안한경우
			if (ny >= 0 && ny < H && nx >= 0 && nx < W && map[ny][nx] != '*')
			{
				if (dir != i) {
					nCnt = cnt + 1;  //방향 바뀌는경우  
				}
				//다른방향으로 탐색하여 ny,nx까지의 겨울횟수가 더 적으면 갱신
				if (check[ny][nx] >= nCnt)
				{
					check[ny][nx] = nCnt;
					q.push({ i,{ny,nx} });
				}
			}

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> W >> H; //너비, 높이
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 'C') C.push_back({ y,x }); //레이저 저장
			check[y][x] = MAX;

		}
	}
	int sy = C[0].first;
	int sx = C[0].second;
	int dy = C[1].first;
	int dx = C[1].second;

	bfs(sy, sx);

	cout << check[dy][dx] << "\n";

}


