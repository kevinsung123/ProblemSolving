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
string map[102];
int H, W;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> H >> W;
		map[0].resize(W + 2, '.');
		map[H + 1].resize(W + 2, '.');
		for (int i = 1; i <= H; i++)
		{
			map[i].clear();
			string tmp;
			cin >> tmp;
			map[i].push_back('.');
			map[i].append(tmp);
			map[i].push_back('.');
		}
		int d[26][102][102];
		memset(d, 0, sizeof(d));
		//key 처리
		string tmp;
		cin >> tmp;
		int check[26] = { 0 };
		memset(check, 0, sizeof(check));
		queue<int> q_key;
		for (int i = 0; i < tmp.size(); i++)
		{
			q_key.push(tmp[i] - 'a'); check[tmp[i] - 'a'] = 1;
		}
		
		while (1)
		{
			int qsize = q_key.size();
			if (qsize == 0) break;
			for (int i = 0; i < qsize; i++) //key의 개수만큼 돌림
			{
			
				bool visited[102][102] = { 0 };
				memset(visited, 0, sizeof(visited));
				int k = q_key.front(); q_key.pop();
				if (check[k]) continue;
				check[k] = 1;
				queue<tuple<int,int>> q;
				q.push({ 0,0 });
				while (!q.empty())
				{
					int y, x;
					tie(y, x) = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int ny = y + dy[dir];
						int nx = x + dx[dir];
						if (ny >= 0 && ny <= H + 1 && nx >= 0 && nx <= W + 1)
						{
							if (visited[ny][nx] || map[ny][nx]=='*') continue; //방문 벽 체크
							if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z') q_key.push(map[ny][nx] - 'a'); q.push({ ny,nx});  //key 처리
							if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z' && check[k]) //해당 키 있을시에
							{
								q.push({ ny,nx });
							}
							if (map[ny][nx] == '$')
							{
								d[k][ny][nx] = 1;
								q.push({ ny,nx });
							}
						}
					}

				}
				
			}
		}
		int ans = 0;
		for (int i = 0; i < 26; i++)
		{
			for (int m = 1; m <= H; m++)
			{
				for (int n = 1; n <= W; n++) if (d[i][m][n]) ans++;
			}
		}
		cout << ans << "\n";
	}
	
}