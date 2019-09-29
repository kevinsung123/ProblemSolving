#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct P {
	int y;
	int x;
	int tm;
	P(int y, int x) : y(y), x(x) {};
	P(int y, int x, int tm) : y(y), x(x), tm(tm) {};
};
queue<P> fire;
queue<P> men;
int T, ans, H, W;
char map[1001][1001];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
void bfs()
{
	bool flag = false;
	while (1)
	{
		int cy, cx, tm, size;
		int ny, nx, ncnt;
		size = fire.size();
		while (size--)
		{
			cy = fire.front().y;
			cx = fire.front().x;
			fire.pop();
			for (int i = 0;i < 4;i++)
			{
				ny = cy + dy[i];
				nx = cx + dx[i];
				//���� ������
				if (ny<0 || ny>H - 1 || nx<0 || nx>W - 1) continue;
				//����� ��ġ�̰ų� ������϶� �Űܰ�������
				if (map[ny][nx] == '.' || map[ny][nx] == '@')
				{
					map[ny][nx] = '*';
					fire.push(P(ny, nx));
				}
			}
		}
		size = men.size();
		while (size--)
		{
			cy = men.front().y;
			cx = men.front().x;
			tm = men.front().tm;
			men.pop();
			for (int i = 0;i < 4;i++)
			{
				ny = cy + dy[i];
				nx = cx + dx[i];
				//Ż���ϸ� break!
				//���Ƕ��� Ʋ��...
				if (ny < 0 || ny >(H - 1) || nx < 0 || nx > (W - 1))
				{
					flag = true;
					break;
				}
				//����� ��ġ�̰ų� ������϶� �Űܰ�������
				if (map[ny][nx] == '.')
				{
					map[ny][nx] = '@';
					men.push(P(ny, nx,tm+1));
				}
			}
		}
		if (flag == true)
		{
			cout << tm + 1 << "\n";
			while (!fire.empty()) fire.pop();
			while (!men.empty()) men.pop();
			break;

		}
		//Ʋ����..
		if(men.empty())
		{
			cout << "IMPOSSIBLE" << "\n";
			while (!fire.empty()) fire.pop();
			while (!men.empty()) men.pop();
			break;
		}
	}
	return;
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> W >> H;
		//Ʋ���κ�... ���̸�ŭ �޾ƾ��Ѵ�!
		for (int i = 0;i < H;i++)
		{
			scanf("%s", map[i]);
			for (int j = 0;j < map[i][j];j++)
			{
			
				if (map[i][j] == '@')
				{
					men.push(P(i, j, 0));
				}
				if (map[i][j] == '*')
				{
					fire.push(P(i, j));
				}
			}
		}
		bfs();

	}
}