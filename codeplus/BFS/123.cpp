#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAX 1e9

int W, H, ans;
char map[101][101];
int check[101][101];
// 0 : �� 1: �� 2: �� 3: ��
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
	//ó�� ���۹ٹ� 
	check[y][x] = 0;

	//queue<Dir> q;
	queue < pair<pair<int,int>, pair<int,int> >> q;

	//ó�� ��ǥ�������� 4������ ����
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


		//4���� Ž��
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nCnt = cnt;


			//��ĭ�ΰ��, �ʾ�, �湮���Ѱ��
			if (ny >= 0 && ny < H && nx >= 0 && nx < W && map[ny][nx] != '*')
			{
				if (dir != i) {
					nCnt = cnt + 1;  //���� �ٲ�°��  
				}
				//�ٸ��������� Ž���Ͽ� ny,nx������ �ܿ�Ƚ���� �� ������ ����
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
	cin >> W >> H; //�ʺ�, ����
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 'C') C.push_back({ y,x }); //������ ����
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


