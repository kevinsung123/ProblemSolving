#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<utility>
#include<functional>
#include<cstring>
#include<string>
using namespace std;
int H, W;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
//string map[102];
char map[102][102];
int check[26];  //�����
int ans; //ã�� ����
bool bfs()
{
	queue<tuple<int, int>> q;
	int visited[102][102];
	memset(visited, 0, sizeof(visited));
	q.push({ 0,0 });
	visited[0][0] = 1;
	bool find = false;
	while (!q.empty())
	{
		int y, x;
		tie(y, x) = q.front(); q.pop();
		// ���� ó��
		if (map[y][x] == '$')
		{
			map[y][x] = '.';
			ans++;
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= 0 && ny <= H + 1 && nx >= 0 && nx <= W + 1)
			{
				if (map[ny][nx] == '*' || visited[ny][nx]) continue; //��, �湮ó��
				if (map[ny][nx] == '.' || map[ny][nx] == '$')//����, �����ó��
				{
					q.push({ ny,nx });
					visited[ny][nx] = 1;
				}
				else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z')//����ó��
				{
					check[map[ny][nx] - 'a'] = 1; //Ű ȹ��
					find = true;
					map[ny][nx] = '.'; //��ó��
					q.push({ ny,nx });
					visited[ny][nx] = 1;
				}
				else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z')
				{
					if (check[map[ny][nx] - 'A'])//���谡 �ִ°��
					{
						map[ny][nx] = '.';
						q.push({ ny,nx });
						visited[ny][nx] = 1;
					}
				}
			}
		}

	}
	return find;
}

int main()
{
	
	int t;
	cin >> t;
	while (t--)
	{

		cin >> H >> W;
		ans = 0;
		memset(check, 0, sizeof(check));

		memset(map, '.', sizeof(map));
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++) cin >> map[i][j];

		}
		//key ó��
		string tmp;
		cin >> tmp;
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] == '0') continue;
			check[tmp[i] - 'a'] = 1;
		}
		while (1)
		{
			bool res = bfs();
			if (!res) break;
		}
		cout << ans << "\n";

	}

}