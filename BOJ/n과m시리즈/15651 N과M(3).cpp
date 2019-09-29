#include<iostream>
using namespace std;
int N, M, ans[9];
void dfs(int index)
{
	
	if (index == M)
	{
		for (int i = 0;i < M;i++)cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1;i <= N;i++)
	{
		ans[index] = i;
		dfs(index + 1);
	}
}

int main()
{
	cin >> N >> M;
	dfs(0);
	return 0;

}