#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
#define MAX 100001

int parent[MAX];  //�θ�
int chk[MAX];	  //Ȯ�� �θ��带 �����ϴ�  �湮�迭
vector<int> child[MAX];//�ڽĸ���Ʈ  => ����Ʈ���� �ƴ϶� k��Ʈ����� ���� 
int N;//����� ����

int main()
{

	ios::sync_with_stdio(false);
	cin >> N;
	int a, b;
	for (int i = 1; i <= N - 1; i++)
	{
		cin >> a >> b;
		child[a].push_back(b);
		child[b].push_back(a);
	}

	chk[1] = 1;//��Ʈ��� �湮����
	queue<int>q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int m = 0; m < child[cur].size(); m++)
		{
			int c = child[cur][m];
			if (chk[c] == 0)  //���� �湮�����ʾҴٸ�
			{
				q.push(c);
				parent[c] = cur; //�θ�������
				chk[c] = 1; //�湮ó��
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}
	
}