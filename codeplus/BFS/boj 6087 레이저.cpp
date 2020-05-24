#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
#include<utility>
using namespace std;
char map[101][101];
int dist[101][101];
int W, H;
vector<pair<int, int>> target;
int dy[] = {1,-1,0,0};
int dx[] = { 0,0,1,-1 };


void bfs()
{
	queue<pair<int,int>> q;
	q.push({ target[0].first,target[0].second });
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			//������ǥ
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			while (ny >= 0 && nx >= 0 && ny < H && nx < W && map[ny][nx] != '*')//������ ������ʰ� ���� �ƴ϶��
			{
				if (!dist[ny][nx])
				{
					dist[ny][nx] = dist[cy][cx] + 1;  //���� ��ǥ���� �ѹ������� ��� ���� �ִ� ������ǥ���� +1�� ���ش�
					q.push({ ny,nx });
				}
				ny += dy[i];
				nx += dx[i];

			}
		}
	}

}

int main()
{
	cin >> W >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W;j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'C') target.push_back({ i,j });
		}
	}
	bfs();



	cout << dist[target[1].first][target[1].second]-1 << "\n";
}