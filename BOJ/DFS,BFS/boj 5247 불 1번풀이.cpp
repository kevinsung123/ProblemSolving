#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
struct F {
	int y;
	int x;
	int time;
	F(int y, int x) : y(y), x(x) {};
	F(int y, int x,int time) : y(y), x(x) ,time(time){};
};
char map[1001][1001] = {0};
int check[1001][1001];
int ans, T, H, W;
queue<F> fire;
queue<F> men;
int start[1][2];
int fstart[1][2];
bool flag;
//�� �� �� ��
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void bfs() 
{
	while (1)
	{
		int size = fire.size();
		int cy, cx, cnt;
		//��ó�� ť�� �һ����ŭ
		while (size--)
		{
			cy = fire.front().y;
			cx = fire.front().x;
			fire.pop();
			//���� time  ��ó��
			for (int i = 0;i < 4;i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				//���� ������ ������
				if (ny<0 || ny>W-1  || nx<0 || nx>H-1) continue;
				
				//������̰ų� ����� ��ġ�ϋ�
				if (map[ny][nx] == '.' || map[ny][nx]=='@')
				{
					map[ny][nx] = '*';
					fire.push(F(ny, nx));
				}

			}
		}
		//����� ó��
		size = men.size();
		while (size--)
		{
			cy = men.front().y;
			cx = men.front().x;
			cnt = men.front().time;
			men.pop();
			for (int i = 0;i < 4;i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if (ny <0 || ny>W-1 || nx<0 || nx>H-1) //=>Ʋ�ǳ�..
				{
					//0�̰ų� ���� �����Ҷ� Ż�⼺��
					flag = true;
					break;
				}
				//������ϋ�
				if (map[ny][nx] == '.')
				{
					map[ny][nx] = '@';
					men.push(F(ny, nx, cnt + 1));
				}
			}
		}

		//��,����� ó�� �� 
		if (flag == true)
		{
			cout << cnt + 1 << "\n";
			//Ż�� �����ϸ� �ʱ�ȭ��
			while (!men.empty()) men.pop();
			while (!fire.empty())fire.pop();
			break;
		}
		if (men.empty())
		{
			while (!men.empty()) men.pop();
			while (!fire.empty())fire.pop();
			cout << "IMPOSSIBLE\n";
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
		
		for (int i = 0;i < W;i++)
		{
			scanf("%s", map[i]);
			for (int j = 0; map[i][j];j++)
			{
				
				if (map[i][j] == '@')
				{
					men.push(F(i, j, 0));
			
				}
				if (map[i][j] == '*')
				{
					fire.push(F(i, j));
				}
			}
		}
		flag = false;
		bfs();
	}
}