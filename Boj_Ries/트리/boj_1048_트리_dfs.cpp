#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, root, ans;
int parent[51];
int child[51];
void dfs(int node) //leaf node 개수를 셈
{
	//지운노드
	if (node == M) return;
	
	//해당노드 자식노드수=0이면 리프노드임
	if (child[node] == 0)
	{
		ans++;
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (parent[i] == node) //현재 input node를 부모로하는 자식노드를 찾아서 dfs
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
			child[parent[i]]++;  //해당 노드의 자식의 개수를 저장
		}
	}
	cin >> M;
	child[parent[M]]--; //지운노드의 자식을 감소
	if (M == root) cout << 0 << "\n";
	else
	{
		dfs(root);
		cout << ans << "\n";
	}
}