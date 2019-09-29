#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
#include<tuple>
#include<cstring>
#include<functional>
#include<string>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int match[[11] = { 0 };
int H, W;
string map[104];
int dirt_size;
struct Node {
	int y;
	int x;
	int dist;
	Node() : Node(0, 0, 0) {};
	Node(int y, int x, int dist) : y(y), x(x), dist(dist) {};
	bool operator<(const Node & b)const { return dist > b.dist; };
};
int main()
{

	int t;
	cin >> t;
	while (t--) //테스트 케이스
	{
		cin >> H >> W;

		//s배열은 상근,죄수1,죄수2 시작 위치 
		//상근은 맵 밖에서 문을 열어줌
		//죄수들은 각각 자기 위치에서 시작
		int d[3][104][104], sy[3] = { 0 }, sx[3] = { 0 }, ycnt = 0, xcnt = 0;
		int sy1, sx1, sy2, sx2;
		sy1 = sx1 = sy2 = sx2 = 0;
		map[0].resize(W + 2);
		map[H + 1].resize(W + 2);
		fill_n(map[0].begin(), W + 2, '.');
		fill_n(map[H + 1].begin(), W + 2, '.');
		//print();
		int cnt = 1;
		for (int i = 1; i <= H; i++)
		{
			string tmp;
			cin >> tmp;
			map[i].clear();
			map[i].push_back('.');
			map[i].append(tmp);
			map[i].push_back('.');
			for (int j = 1; j <= W; j++)
			{
				if (map[i][j] == '$')//죄수 
				{
					//죄수들 위치는 어차피 빈공간
					sy[cnt] = i;
					sx[cnt] = j;
					cnt++;

				}

			}
		}
		//print();
		//0: 상근  1:죄수1 2: 죄수2
		for (int k = 0; k < 3; k++)
		{

			//무한대 초기화
			for (int i = 0; i <= H + 1; i++)
			{
				for (int j = 0; j <= W + 1; j++) d[k][i][j] = 1e9;
			}
			//dist 거리가 작은것부터 나와야한다.
			priority_queue<Node> pq;
			pq.push({ sy[k],sx[k],0 });
			d[k][sy[k]][sx[k]] = 0;
			int check[102][102];
			memset(check, 0, sizeof(check));
			while (!pq.empty())
			{
				int y, x, dist;
				do {
					y= pq.top().y;
					x = pq.top().x;
					pq.pop();
				} while (check[y][x]);
				if (check[y][x]) continue;
				check[y][x] = 1;
				for (int dir = 0; dir < 4; dir++)
				{
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if (ny<0 || ny>H + 1 || nx<0 || nx>W + 1) continue; //범위 체크
					if (check[ny][nx] || map[ny][nx] == '*')continue;   // 방문 + 벽 체크
					int ndist = d[k][y][x];
					if (map[ny][nx] == '#') ndist++;
					if (d[k][ny][nx] > ndist)//문을 딴 횟수가 크다면 이동
					{
						d[k][ny][nx] = ndist;
						pq.push({ny,nx,ndist });

					}

				}
			}

		}
		int ans = 1e9;
		//상근,죄수1, 죄수2가 세명이 동시에 만나는 최소 지점을 찾음
		int y, x;
		y = x = 0;
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (map[i][j] != '*')//벽인경우 제외
				{
					int res = d[0][i][j] + d[1][i][j] + d[2][i][j] - 2 * (map[i][j] == '#');
					if (ans > res)
					{
						ans = res;
						y = i, x = j;

					}

				}
			}
		}
		cout << ans << "\n";
	}
}