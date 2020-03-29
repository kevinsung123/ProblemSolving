#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<utility>
#include<cstring>
using namespace std;
#define MAX 1000000
int N, M, K;
int r, c, s;
int map[51][51]; //맵 저장
int tmp[51][51]; //임시저장
vector<pair<int, pair<int, int>>> rot;  //연산저장
int ans;
int vis[51];
int match[6];
void print()
{

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}


void copy()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) tmp[i][j] = map[i][j];
	}

}
void restore()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) map[i][j] = tmp[i][j];
	}

}
int getMin()
{
	int ret = MAX;
	//각행을 돌면서 최솟값을 비교하여 구함
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		//열을 돌면서 sum을구함
		for (int j = 1; j <= M; j++)
		{
			sum += map[i][j];
		}
		ret = min(ret, sum);

	}

	return ret;
}
void rotate(int r, int c, int s) //y,x, 길이
{

	
	int cnt = s ;//회전을 반복할 횟수
	while (cnt > 0)
	{
		//첫번째원소는 저장했다가 마지막에 저장
		int tmp = map[r - cnt][c - cnt];
		//반시계방향으로 대입
		//좌->하->우>상
		//좌 x좌표는 고정
		for (int y = r - cnt; y < r + cnt; y++)
		{
			map[y][c - cnt] = map[y + 1][c - cnt];
		}
		//cout << "좌 =====" << "\n";
		//print();
		//하 y좌표고정
		for (int x = c - cnt; x < c + cnt; x++)
		{
			map[r + cnt][x] = map[r + cnt][x + 1];
		}
		//cout << "하 =====" << "\n";
		//print();
		//우 x좌표고정
		for (int y = r + cnt; y > r - cnt; y--)
		{
			map[y][c + cnt] = map[y - 1][c + cnt];
		}
		//cout << "우 =====" << "\n";
		//print();
		//상 y좌표고정
		for (int x = c + cnt; x > c - cnt; x--)
		{
			map[r - cnt][x] = map[r - cnt][x - 1];

		}

		map[r - cnt][c - cnt + 1] = tmp;
		//cout << "상 =====" << "\n";
		//print();

		cnt--;
	}
}
void solve(int idx)
{
	//k번돌렸으면 최솟값 비교해서 구하여 리턴
	if (idx == K)
	{	
		//회전 순서가 모두 정해진뒤에 돌린다
		//초기상태로 돌린 뒤 돌림!
		restore(); 
		for (int i = 0; i < K; i++)
		{
			//cout << match[i] << "\n";
			int idx = match[i];
			int r,c,s;
			r = rot[idx].second.first;
			c = rot[idx].second.second;
			s = rot[idx].first;
			rotate(r, c, s);

		}

		ans = min(ans, getMin());
		return;
	}
	for (int i = 0; i < K; i++)
	{
		if (vis[i] == 0)
		{
			int r, c, s;
			s = rot[i].first; //길이
			r = rot[i].second.first; //y
			c = rot[i].second.second; //x

			vis[i] = 1;
			//회전할 순서를 다 정해주고 돌린다!
			match[idx] = i;
			solve(idx + 1);
			vis[i] = 0;
			
		
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			cin >> map[y][x];
			tmp[y][x] = map[y][x];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int r, c, s;
		cin >> r >> c >> s;
		rot.push_back({ s,{r,c} });
	}
	//ans 초기화
	ans = 1e9;
	//초기값 맵값을 저장 해둔뒤, 회전순서시 restore한다
	copy();
	solve(0);
	cout << ans << "\n";
}