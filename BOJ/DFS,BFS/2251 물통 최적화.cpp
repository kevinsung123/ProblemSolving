#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<tuple>
#include<set>
#include<queue>
using namespace std;
int check[201][201][201];
int main()
{
	ios::sync_with_stdio(false);
	int max_a[3] = { 0 };	
	cin >> max_a[0] >> max_a[1] >> max_a[2];  //���� �ִ�뷮
	int arr[3] = { 0,0,max_a[2] };// ���� ����
	set<int> res;//��� 
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,max_a[2] });
	check[0][0][max_a[2]];
	while (!q.empty())
	{
		int a, b, c;
		tie(a, b, c) = q.front(); q.pop();
		arr[0] = a; arr[1] = b; arr[2] = c;//���� ���� ����
		check[a][b][c] = 1;  //�湮ó��
		//printf("a=%d b=%d c=%d\n", a, b, c);
		if (a == 0) res.insert(c);  //A=0�϶� C���Ǿ� ���
		for (int i = 0; i < 3; i++) //���� ������ �ִ� �� ã��
		{
			if (arr[i] < max_a[i])//���� ������ �ִٸ�
			{
				for (int j = 0; j < 3; j++)//���� �ִ� �뿡�� �ű��
				{
					int next[3] = { arr[0],arr[1],arr[2] };  //��������
					if (i == j || arr[j] == 0) continue;
					int diff = min(arr[j],abs(max_a[i]-arr[i])); // �������� ������ max-���� or �����ִ°��� �ִ� �� ������
					next[i] += diff;
					next[j] -= diff;
					if (check[next[0]][next[1]][next[2]]) continue;
					q.push({ next[0],next[1],next[2] });
					//printf("���� %d %d %d\n", next[0], next[1], next[2]);
				
				}
			}
		}
	}
	
	for (auto x : res)cout << x << " ";
	cout << "\n";

}