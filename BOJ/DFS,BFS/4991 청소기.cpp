#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<functional>
#include<tuple>
#include<queue>
using namespace std;
string map[22];
int d[12][22][22];
int check[22][22]; //���� ã������
int dirt_size;
int H, W;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int sy, sx;
void bfs(int idx, int sy, int sx)
{
	memset(check, 0, sizeof(check));
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	check[sy][sx] = 1;
	d[idx][sy][sx] = 0; //�ʿ����� �̵�Ƚ��
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny >= 0 && ny < H && nx >= 0 && nx < W)
			{
				if (check[ny][nx] || map[ny][nx] == 'x')continue;  //�湮, �ⱸ üũ
				if (d[idx][ny][nx] > d[idx][y][x] + 1)
				{
					check[ny][nx] = 1;
					d[idx][ny][nx] = d[idx][y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main()
{

	while (1)
	{
		cin >> W >> H; //����,����
		if (H == 0 && W == 0) break;
		vector<pair<int, pair<int, int>>> dist;
		for (int m = 0; m < 12; m++) for (int i = 0; i < 22; i++) for (int j = 0; j < 22; j++) d[m][i][j] = 1e9;
		for (int i = 0; i < 22; i++) map[i].clear();
		int idx = 1;
		for (int i = 0; i < H; i++)
		{
			cin >> map[i];

			for (int j = 0; j < W; j++)
			{
				if (map[i][j] == 'o')
				{
					sy = i, sx = j;
					map[i][j] = '.';
				}
				//������ ������ max 10���̹Ƿ� idx������
				if (map[i][j] == '*')
				{
					dist.push_back({ idx, {i,j} });
					idx++;
				}
			}
		}
		dirt_size = dist.size();
		if (dirt_size == 0)
		{
			puts("0");
			continue;
		}
		//�� ó�� ���������� bfs
		bfs(0,sy, sx);
		sort(dist.begin(), dist.end());
		//���������� bfs�Ÿ� ����
		for (int i = 0; i < dirt_size; i++) bfs(dist[i].first, dist[i].second.first, dist[i].second.second);
		int ans = 1e9;
		do
		{
			int tmp = d[0][dist[0].second.first][dist[0].second.second];  //���������� ����
			for (int i = 0; i < dirt_size - 1; i++)
			{
				tmp += d[dist[i].first][dist[i + 1].second.first][dist[i + 1].second.second];  //������ ���� ���� �Ÿ�
			}
			ans = min(ans, tmp);

		} while (next_permutation(dist.begin(), dist.end()));

		if (ans == 1e9) cout << -1 << "\n";
		else cout << ans << "\n";

	}





}