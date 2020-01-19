#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

/*
1. 2차원맵 (0,0)에서 시작 
2. 조건 : 
		1) 지금까지 지난 알파벳은 x
		2) 4방향으로 계속 탐색 dfs
		3) 길이를 현재까지 길이와 비교하여 갱신해준다
		4) backtracking을 해준다!

*/

char map[21][21];
bool chk[21][21], alpha[26];
int R, C;
int ans;
//동서남북 순서
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void dfs(int y, int x, int len)
{
	//최대길이 갱신
	ans = max(ans, len);
	chk[y][x] = true;
	alpha[map[y][x]-'A'] = true;
	//printf("y : %d , x :%d\n", y, x);
	for (int k = 0; k < 4; k++)
	{
		int ny = y + dy[k];
		int nx = x + dx[k];
		/*
			1. 범위를 벗어나지않고
			2. 아직 방문하지 않고 현재까지 나온 알파벳이 아니라면 계속 탐색
		*/

		if (ny >= 0 && nx >= 0 && ny < R && nx < C && !alpha[map[ny][nx]-'A'] && !chk[ny][nx])
		{
			dfs(ny, nx, len + 1);
		}
	}
	//dfs 탐색 순서를 떠올리자 !! 그래프 생각 
	chk[y][x] = false;
	alpha[map[y][x] - 'A'] = false;
	
}


int main()
{

	ios::sync_with_stdio(false);
	cin >> R >> C;
	for (int y = 0; y < R; y++)  //행
		for (int x = 0; x < C; x++) cin >> map[y][x];  //열
	dfs(0, 0, 1); //시작점도 포함하므로 처음길이1
	cout << ans << endl;
}