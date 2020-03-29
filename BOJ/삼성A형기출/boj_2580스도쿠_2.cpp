#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int map[9][9];  //스도쿠맵
vector<pair<int, int>> arr; //빈칸의 좌표
int c;  //빈칸개수

//가로세로검사, 3X3 정사각형 검사
int check(int y, int x,int num)
{
	int sy = y / 3; //몫
	int sx = x / 3;

	int flag = 1;

	//가로 및 세로 검사 
	for (int i = 0; i < 9; i++)
	{
		if (num == map[y][i] || num == map[i][x])
		{
			flag = 0; //같은숫자가나오면 false
			return flag;
		}
	}
	//3X3검사
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
	//모두 채우면 스도쿠 출력
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

	for (int i = 1; i <= 9; i++)  //빈칸에 1-9까지 채워넣어본다
	{
		if (check(y, x,i) == 1)  //해당 좌표에 값을 넣고 가능한지 확인
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
			// 빈칸의 좌표를 vector에 저장
			if (map[i][j] == 0) arr.push_back({ i, j });
		}
	}
	c = arr.size();
	dfs(0);

}

