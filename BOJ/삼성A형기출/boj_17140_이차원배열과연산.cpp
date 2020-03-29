
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
	//1�� ����� 1���帧
	for (int t = 0; t <= 100; t++)
	{
		if (map[r][c] == k)
		{
			cout << t << "\n";
			return;
		}

		//N>=M R����(��)
		if (N >= M)
		{
			for (int y = 1; y <= N; y++)  //��
			{
				//priority_queue< pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
				vector < pii> pq;
				//�迭 �ʱ�ȭ
				memset(cnt, 0, sizeof(cnt));
				for (int x = 1; x <= M; x++)
				{

					if (map[y][x] != 0)
					{
						cnt[map[y][x]]+=1;  //�ش� ���� count
						map[y][x] = 0;  //�ʱ�ȭ
					}
				}

				//(����Ƚ��, ����) 
				for (int m = 1; m <= 100; m++)
				{
					if (cnt[m] > 0) pq.push_back({ cnt[m],m });
				}

				//�� ���� �� ���̴�  ���� X2(����Ƚ��,����)
				int len = pq.size() * 2;
				//�� �ִ밪 update
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
		else//C���� ��
		{
			//��
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

				//pq�� �־ ����
				for (int m = 1; m <= 100; m++)
				{
					if (cnt[m] > 0)
						pq.push_back({ cnt[m],m });
				}
				sort(pq.begin(), pq.end());
				//�� update
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

	//100�� �ʰ���
	cout << -1 << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	//r,c,k �ʱ� �迭 �Է¹���

	N = M = 3;   //�ʱ� ��,�� 3X3
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++) cin >> map[i][j];
	}
	
	//solve();
	



}