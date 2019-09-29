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
	while (t--) //�׽�Ʈ ���̽�
	{
		cin >> H >> W;

		//s�迭�� ���,�˼�1,�˼�2 ���� ��ġ 
		//����� �� �ۿ��� ���� ������
		//�˼����� ���� �ڱ� ��ġ���� ����
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
				if (map[i][j] == '$')//�˼� 
				{
					//�˼��� ��ġ�� ������ �����
					sy[cnt] = i;
					sx[cnt] = j;
					cnt++;

				}

			}
		}
		//print();
		//0: ���  1:�˼�1 2: �˼�2
		for (int k = 0; k < 3; k++)
		{

			//���Ѵ� �ʱ�ȭ
			for (int i = 0; i <= H + 1; i++)
			{
				for (int j = 0; j <= W + 1; j++) d[k][i][j] = 1e9;
			}
			//dist �Ÿ��� �����ͺ��� ���;��Ѵ�.
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
					if (ny<0 || ny>H + 1 || nx<0 || nx>W + 1) continue; //���� üũ
					if (check[ny][nx] || map[ny][nx] == '*')continue;   // �湮 + �� üũ
					int ndist = d[k][y][x];
					if (map[ny][nx] == '#') ndist++;
					if (d[k][ny][nx] > ndist)//���� �� Ƚ���� ũ�ٸ� �̵�
					{
						d[k][ny][nx] = ndist;
						pq.push({ny,nx,ndist });

					}

				}
			}

		}
		int ans = 1e9;
		//���,�˼�1, �˼�2�� ������ ���ÿ� ������ �ּ� ������ ã��
		int y, x;
		y = x = 0;
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (map[i][j] != '*')//���ΰ�� ����
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