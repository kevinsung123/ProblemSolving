#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int W, H, ans;
char map[101][101];
int check[101][101];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
vector<pair<int,int>> C;

void dfs(int y, int x, int dir) //y,x,��������,��������
{

	cout << "y=" << y << ", x=" << x  << ", dir=" << dir << "\n";
	



	if (C[1].first == y && C[1].second == x) //������ ������ 
	{
		cout << "�ſＳġȽ��=" << ans << "\n";
		return;
	}

	if (map[y][x] == '*' || y<0 || y>H || x<0 || x>W) return;

		


	for(int c=0;c<4;c++)
	{

		//���� �湮�� ��ǥ
		int ny = y + dy[c];
		int nx = x + dx[c];

		//cout << "ny=" << ny << ", nx=" << nx << ",map="<<map[ny][nx]<<"\n";

		//��ĭ�ΰ��, �ʾ�, �湮���Ѱ��
		if (map[ny][nx] == '.' && ny >= 0 && ny < H && nx >= 0 && nx < W  &&  check[ny][nx] >= check[y][x] )
		{
			//���� �ٸ��� �ſＳġȽ�� ����
			if (dir != c) ans++; 

			//�湮üũ
			check[ny][nx] = check[y][x] + 1;
			dfs(ny, nx, c);  //��������
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
			check[y][x] = 987654321;

		}
	}
	int sy = C[0].first;
	int sx = C[0].second;
	int dy= C[1].first;
	int dx = C[1].second;
	//ó�� ������ �湮Ƚ��0
	check[sy][sx] = 0;

	dfs(sy, sx,0);

	cout << check[dy][dx] << "\n";

}