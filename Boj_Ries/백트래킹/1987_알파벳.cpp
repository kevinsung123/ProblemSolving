#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

/*
1. 2������ (0,0)���� ���� 
2. ���� : 
		1) ���ݱ��� ���� ���ĺ��� x
		2) 4�������� ��� Ž�� dfs
		3) ���̸� ������� ���̿� ���Ͽ� �������ش�
		4) backtracking�� ���ش�!

*/

char map[21][21];
bool chk[21][21], alpha[26];
int R, C;
int ans;
//�������� ����
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void dfs(int y, int x, int len)
{
	//�ִ���� ����
	ans = max(ans, len);
	chk[y][x] = true;
	alpha[map[y][x]-'A'] = true;
	//printf("y : %d , x :%d\n", y, x);
	for (int k = 0; k < 4; k++)
	{
		int ny = y + dy[k];
		int nx = x + dx[k];
		/*
			1. ������ ������ʰ�
			2. ���� �湮���� �ʰ� ������� ���� ���ĺ��� �ƴ϶�� ��� Ž��
		*/

		if (ny >= 0 && nx >= 0 && ny < R && nx < C && !alpha[map[ny][nx]-'A'] && !chk[ny][nx])
		{
			dfs(ny, nx, len + 1);
		}
	}
	//dfs Ž�� ������ ���ø��� !! �׷��� ���� 
	chk[y][x] = false;
	alpha[map[y][x] - 'A'] = false;
	
}


int main()
{

	ios::sync_with_stdio(false);
	cin >> R >> C;
	for (int y = 0; y < R; y++)  //��
		for (int x = 0; x < C; x++) cin >> map[y][x];  //��
	dfs(0, 0, 1); //�������� �����ϹǷ� ó������1
	cout << ans << endl;
}