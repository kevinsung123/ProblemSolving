#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int map[9][9];  //�������
vector<pair<int, int>> arr; //��ĭ�� ��ǥ
int c;  //��ĭ����

//���μ��ΰ˻�, 3X3 ���簢�� �˻�
int check(int y, int x,int num)
{
	int sy = y / 3; //��
	int sx = x / 3;

	int flag = 1;

	//���� �� ���� �˻� 
	for (int i = 0; i < 9; i++)
	{
		if (num == map[y][i] || num == map[i][x])
		{
			flag = 0; //�������ڰ������� false
			return flag;
		}
	}
	//3X3�˻�
	for (int m = sy * 3; m < sy* 3 + 3; m++)
	{
		for (int n = sx * 3; n < sx* 3 + 3; n++)
		{

			if (num == map[m][n])
			{
				flag = 0;
				return flag;
			}
		}
	}
	return flag;
}

void dfs(int cnt)
{
	//��� ä��� ������ ���
	if (c == cnt)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) cout << map[i][j] << " ";
			cout << "\n";
		}
		exit(0);
		return;
	}
	int y = arr[cnt].first;
	int x = arr[cnt].second;

	for (int i = 1; i <= 9; i++)  //��ĭ�� 1-9���� ä���־��
	{
		if (check(y, x,i) == 1)  //�ش� ��ǥ�� ���� �ְ� �������� Ȯ��
		{
			map[y][x] = i;
			dfs(cnt + 1);
			map[y][x] = 0;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);

	for (int i = 0; i < 9; i++)//y
	{

		for (int j = 0; j < 9; j++)//x
		{
			cin >> map[i][j];
			// ��ĭ�� ��ǥ�� vector�� ����
			if (map[i][j] == 0) arr.push_back({ i, j });
		}
	}
	c = arr.size();
	dfs(0);

}

