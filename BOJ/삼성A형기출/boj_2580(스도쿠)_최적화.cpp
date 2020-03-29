#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int map[9][9]; 
bool row[9][10]; //row[i][j] : i�����࿡ j���� ä������������
bool col[9][10]; //col[]i[j] : i�������� j���� ä������������
bool squ[9][10];
vector<pair<int, int>> arr;


void dfs(int cnt)
{
	if (cnt == arr.size())
	{
		//for (int m = 0; m < arr.size(); m++)
			//cout << arr[m].first << ", " << arr[m].second << " ="<<map[arr[m].first][arr[m].second] << "\n";
		//cout << "\n";
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) cout << map[i][j] << " ";
			cout << "\n";
			
		}
		exit(0);
			
	}
	int y = arr[cnt].first;
	int x = arr[cnt].second;

	for (int i = 1; i <= 9; i++)
	{
		if (row[y][i] == true || col[x][i] == true || squ[(y / 3) * 3 + (x / 3)][i] == true) continue;
		row[y][i] = col[x][i] = squ[(y / 3) * 3 + (x / 3)][i] = true;
		map[y][x] = i;
		dfs(cnt + 1);
		map[y][x] = 0;
		row[y][i] = col[x][i] = squ[(y / 3) * 3 + (x / 3)][i] = false;
		

	}
}

int main()
{
	ios::sync_with_stdio(false);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0) arr.push_back({ i,j });
			else
			{
				row[i][map[i][j]] = true; //��
				col[j][map[i][j]] = true; //��
				squ[(i / 3) * 3 + (j / 3)][map[i][j]] = true;//����簢��
			}
		
		}
	}

	dfs(0);

	return 0;
}