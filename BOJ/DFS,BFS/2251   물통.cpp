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
	cin >> m_arr[0] >> m_arr[1] >> m_arr[2]; //�ִ� ���Ǿ�
	int arr[3] = { 0,0,m_arr[2] };   //���� ���Ǿ�
	vector<int> res;
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,arr[2] });  //ó�� ���� a,b����ְ� c�� ��
	check[0][0][arr[2]] = 1;
	while (!q.empty())
	{
		int a, b, c;
		tie(a, b, c) = q.front();
		arr[0] = a, arr[1] = b, arr[2] = c;  //���� ���� ����
		q.pop();
		check[a][b][c] = 1;
		if (a == 0)//��������  A=0�϶� C�� ���Ǿ�
		{
			res.push_back(c);

		}
		//printf("������ ���ǻ��� a=%d b=%d c=%d\n", a, b, c);
		//���� �ű�� ����
		for (int i = 0; i < 3; i++)
		{
			if (arr[i] < m_arr[i]) //���� ���·� �Ǵ� ���� ������ �ִ� ���
			{
				if (arr[(i + 1) % 3] != 0)
				{
					int tmp[3] = { arr[0],arr[1],arr[2] };
					int j = (i + 1) % 3;
					if (tmp[i] + tmp[j] <= m_arr[i]) //���� ��ġ�� ���� ���
					{
						tmp[i] +=tmp[j];
						tmp[j] = 0;
					}
					else//���� ��ġ�°��
					{
						tmp[j] = tmp[j] - abs(m_arr[i] - tmp[i]);
						tmp[i] = m_arr[i];
						
					}
					if (check[tmp[0]][tmp[1]][tmp[2]]) continue;  //�̹� �����
					q.push({ tmp[0],tmp[1],tmp[2] });
					//printf("���� ���� : %d %d %d\n", tmp[0], tmp[1], tmp[2]);
				}
				if (arr[(i + 2) % 3] != 0)
				{
					int tmp[3] = { arr[0],arr[1],arr[2] };
					int j = (i + 2) % 3;
					if (tmp[i] + tmp[j] <= m_arr[i]) //���� ��ġ�� ���� ���
					{
						tmp[i] += tmp[j];
						tmp[j] = 0;
					}
					else//���� ��ġ�°��
					{
						tmp[j] = tmp[j] - abs(m_arr[i] - tmp[i]);
						tmp[i] = m_arr[i];
					
					}
					if (check[tmp[0]][tmp[1]][tmp[2]]) continue;  //�̹� �����
					
					q.push({ tmp[0],tmp[1],tmp[2] });
					//printf("���� ���� : %d %d %d\n", tmp[0], tmp[1], tmp[2]);
				}
			}
		}
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (auto x : res) cout << x << " ";





}