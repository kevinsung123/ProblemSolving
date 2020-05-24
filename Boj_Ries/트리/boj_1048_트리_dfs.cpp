#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, root, ans;
int parent[51];
int child[51];
void dfs(int node) //leaf node ������ ��
{
	//������
	if (node == M) return;
	
	//�ش��� �ڽĳ���=0�̸� ���������
	if (child[node] == 0)
	{
		ans++;
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (parent[i] == node) //���� input node�� �θ���ϴ� �ڽĳ�带 ã�Ƽ� dfs
				dfs(i);
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> parent[i];
		if (parent[i] == -1) root = i;
		else {
			child[parent[i]]++;  //�ش� ����� �ڽ��� ������ ����
		}
	}
	cin >> M;
	child[parent[M]]--; //�������� �ڽ��� ����
	if (M == root) cout << 0 << "\n";
	else
	{
		dfs(root);
		cout << ans << "\n";
	}
}