
#include<cstring>
#include<cstdio>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int ans, N, M, r, c, k;
int map[101][101];
int cnt[101];

void solve()
{
	//1번 연산시 1초흐름
	for (int t = 0; t <= 100; t++)
	{
		if (map[r][c] == k)
		{
			cout << t << "\n";
			return;
		}

		//N>=M R연산(행)
		if (N >= M)
		{
			for (int y = 1; y <= N; y++)  //행
			{
				//priority_queue< pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
				vector < pii> pq;
				//배열 초기화
				memset(cnt, 0, sizeof(cnt));
				for (int x = 1; x <= M; x++)
				{

					if (map[y][x] != 0)
					{
						cnt[map[y][x]]+=1;  //해당 숫자 count
						map[y][x] = 0;  //초기화
					}
				}

				//(등장횟수, 숫자) 
				for (int m = 1; m <= 100; m++)
				{
					if (cnt[m] > 0) pq.push_back({ cnt[m],m });
				}

				//이 행의 열 길이는  숫자 X2(등장횟수,숫자)
				int len = pq.size() * 2;
				//열 최대값 update
				M = max(M, len);
				sort(pq.begin(), pq.end());
				for (int x = 1; x <= len; x += 2)
				{
					map[y][x] = pq.front().second;
					map[y][x + 1] = pq.front().first;
					pq.erase(pq.begin());
				}
			}
			

		}
		else//C연산 열
		{
			//열
			for (int x = 1; x <= M; x++)
			{
				//priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
				vector < pii> pq;
				memset(cnt, 0, sizeof(cnt));
				for (int y = 1; y <= N; y++)
				{
					if (map[y][x] != 0)
					{
						cnt[map[y][x]]++;
						map[y][x] = 0;
					}
				}

				//pq에 넣어서 정렬
				for (int m = 1; m <= 100; m++)
				{
					if (cnt[m] > 0)
						pq.push_back({ cnt[m],m });
				}
				sort(pq.begin(), pq.end());
				//행 update
				int len = pq.size() * 2;
				N = max(N, len);
				for (int y = 1; y <= len; y+=2)
				{
					map[y][x] = pq.front().second;
					map[y + 1][x] = pq.front().first;
					pq.erase(pq.begin());
				}
			}
		}
	
	}

	//100초 초과시
	cout << -1 << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	//r,c,k 초기 배열 입력받음

	N = M = 3;   //초기 행,열 3X3
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++) cin >> map[i][j];
	}
	
	//solve();
	



}