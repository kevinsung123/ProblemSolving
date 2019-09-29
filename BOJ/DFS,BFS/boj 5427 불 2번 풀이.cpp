#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

char map[1001][1001] = { 0 };
queue<pair< pair<int, int>, int>> men;
queue<pair<int, int>> fire;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
bool check = false;

int main()
{
	int TestCase;
	scanf("%d", &TestCase);
	for (; TestCase--;)
	{
		int w, h;
		scanf("%d %d", &w, &h);
		for (int i = 0; i < h; i++)
		{
			scanf("%s", map[i]);
			for (int j = 0; map[i][j]; j++)
			{
				if (map[i][j] == '@')
				{
					men.push(make_pair(make_pair(i, j), 0));
				}
				else if (map[i][j] == '*')
				{
					fire.push(make_pair(i, j));
				}
			}
		}
		check = false;
		while (1)
		{
			int size;
			int qx, qy, count;
			size = fire.size();
			while (size--) {
				qx = fire.front().second;
				qy = fire.front().first;
				fire.pop();

				for (int i = 0; i < 4; i++)
				{
					if (qx + dx[i] < 0 || qx + dx[i] >= w || qy + dy[i] < 0 || qy + dy[i] >= h)continue;
					if (map[qy + dy[i]][qx + dx[i]] == '.' || map[qy + dy[i]][qx + dx[i]] == '@')
					{
						map[qy + dy[i]][qx + dx[i]] = '*';
						fire.push(make_pair(qy + dy[i], qx + dx[i]));
					}
				}
			}

			size = men.size();
			while (size--) {
				qx = men.front().first.second;
				qy = men.front().first.first;
				count = men.front().second;
				men.pop();

				for (int i = 0; i < 4; i++)
				{
					if (qx + dx[i] < 0 || qx + dx[i] >= w || qy + dy[i] < 0 || qy + dy[i] >= h)
					{
						check = true;
						break;
					}
					if (map[qy + dy[i]][qx + dx[i]] == '.')
					{
						map[qy + dy[i]][qx + dx[i]] = '@';
						men.push(make_pair(make_pair(qy + dy[i], qx + dx[i]), count + 1));
					}
				}
			}
			if (check == true)
			{
				printf("%d\n", count + 1);
				while (!men.empty())men.pop();
				while (!fire.empty())fire.pop();
				break;
			}
			if (men.empty())
			{
				while (!men.empty())men.pop();
				while (!fire.empty())fire.pop();
				printf("IMPOSSIBLE\n");
				break;
			}

		}

	}
	return 0;
}