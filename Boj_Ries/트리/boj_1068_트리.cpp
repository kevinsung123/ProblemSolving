#include<iostream>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
int M;
int parent[51];
vector<int> child[51];
int chk[51];
int ans;


void bfs(int node)
{
	queue<int>q;
	q.push(node);
	chk[node] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		//�ڽĳ�尡 �ִ°�� �׸��� leaf node�� ����� ���
		if (child[cur].size() == 0 || (child[cur].size() == 1 && child[cur][0]==M))
		{
			ans++;
		}
		else {

			for (int i = 0; i < child[cur].size(); i++)
			{
				int next = child[cur][i];
				if (chk[next] == 0)
				{
					if (parent[next] != -2) //������ ��尡 �ƴ϶��
						q.push(next);

				}
				
			}
		}
		



	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N;  //����
	int root = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> parent[i]; //�θ��� ����
		if (parent[i] != -1) //��Ʈ�� �ƴ϶��
			child[parent[i]].push_back(i); //�ڽĳ�� ����
		else if (parent[i] == -1)
			root = i;
	}
	cin >> M; //������

	//����°���
	parent[M] = -2;
	//�ڽĳ�� ����°���
	for (int i = 0; i < N; i++)
	{
		if (parent[i] == M) parent[i] = -2;
	}

	//��Ʈ��带 ã�Ƽ� ����
	if (root == M) cout << 0 << "\n";
	else {
		bfs(root);
		cout << ans << "\n";
	}

