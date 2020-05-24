#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
#include<utility>
using namespace std;
#define MAX 987654321
char map[101][101];
int dist[101][101];
int W, H;
vector<pair<int, int>> target;
// 0 : 북 1: 동 2: 남 3: 서
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void bfs()
{
	//방향, y,x좌표
	queue<pair<pair<int,int>, pair<int, int>>> q;

	//처음 시작시 4방향모두 넣음
	//처음 방문하는 지점은 거울 설치 =0
	dist[target[0].first][target[0].second] = 0;
	for (int i = 0; i < 4; i++)
		q.push({ {i,0},{ target[0].first,target[0].second } });


	while (!q.empty())
	{
		int dir = q.front().first.first;  
		int cnt = q.front().first.second;

		int cy = q.front().second.first;
		int cx = q.front().second.second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			//다음좌표
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int ncnt = cnt;
			//범위안에 있다면
			if (ny >= 0 && ny < H && nx >= 0 && nx < W && map[ny][nx] != '*')
			{
				//방향다른경우
				if (dir != i)
				{
					ncnt = cnt + 1;  //다음 겨울설치횟수1증가
				}
				//거울설치횧수가 더 작은것으로 갱신
				if (dist[ny][nx] >= ncnt)
				{
					dist[ny][nx] = ncnt;
					q.push({ {i,ncnt},{ny,nx} });
				}
			}
		}
	}

}

int main()
{
	cin >> W >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			dist[i][j] = MAX;
			cin >> map[i][j];
			if (map[i][j] == 'C') target.push_back({ i,j });
		}
	}

	bfs();



	cout << dist[target[1].first][target[1].second] << "\n";
}