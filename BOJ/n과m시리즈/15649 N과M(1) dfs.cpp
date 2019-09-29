#include<iostream>
#include<cstdio>
using namespace std;
int n, m, ans[9];
void dfs(int index, int vis)
{
	
	if (index == m)
	{
		for (int i = 0; i<m ;i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (!(vis & (1 << i)))
		{
			ans[index] = i;
			dfs(index + 1, vis | (1 << i));
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	dfs(0, 0);
	return 0;
}