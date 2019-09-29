#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<tuple>
using namespace std;
int check[201][201][201];
int main()
{
	ios::sync_with_stdio(false);
	int m_arr[3];
	cin >> m_arr[0] >> m_arr[1] >> m_arr[2]; //최대 물의양
	int arr[3] = { 0,0,m_arr[2] };   //현재 물의양
	vector<int> res;
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,arr[2] });  //처음 상태 a,b비어있고 c만 물
	check[0][0][arr[2]] = 1;
	while (!q.empty())
	{
		int a, b, c;
		tie(a, b, c) = q.front();
		arr[0] = a, arr[1] = b, arr[2] = c;  //현재 상태 갱신
		q.pop();
		check[a][b][c] = 1;
		if (a == 0)//종결조건  A=0일때 C의 물의양
		{
			res.push_back(c);

		}
		//printf("현재의 물의상태 a=%d b=%d c=%d\n", a, b, c);
		//물을 옮기는 과정
		for (int i = 0; i < 3; i++)
		{
			if (arr[i] < m_arr[i]) //현재 상태로 판단 물을 넣을수 있는 경우
			{
				if (arr[(i + 1) % 3] != 0)
				{
					int tmp[3] = { arr[0],arr[1],arr[2] };
					int j = (i + 1) % 3;
					if (tmp[i] + tmp[j] <= m_arr[i]) //물이 넘치지 않은 경우
					{
						tmp[i] +=tmp[j];
						tmp[j] = 0;
					}
					else//물이 넘치는경우
					{
						tmp[j] = tmp[j] - abs(m_arr[i] - tmp[i]);
						tmp[i] = m_arr[i];
						
					}
					if (check[tmp[0]][tmp[1]][tmp[2]]) continue;  //이미 센경우
					q.push({ tmp[0],tmp[1],tmp[2] });
					//printf("다음 상태 : %d %d %d\n", tmp[0], tmp[1], tmp[2]);
				}
				if (arr[(i + 2) % 3] != 0)
				{
					int tmp[3] = { arr[0],arr[1],arr[2] };
					int j = (i + 2) % 3;
					if (tmp[i] + tmp[j] <= m_arr[i]) //물이 넘치지 않은 경우
					{
						tmp[i] += tmp[j];
						tmp[j] = 0;
					}
					else//물이 넘치는경우
					{
						tmp[j] = tmp[j] - abs(m_arr[i] - tmp[i]);
						tmp[i] = m_arr[i];
					
					}
					if (check[tmp[0]][tmp[1]][tmp[2]]) continue;  //이미 센경우
					
					q.push({ tmp[0],tmp[1],tmp[2] });
					//printf("다음 상태 : %d %d %d\n", tmp[0], tmp[1], tmp[2]);
				}
			}
		}
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (auto x : res) cout << x << " ";





}