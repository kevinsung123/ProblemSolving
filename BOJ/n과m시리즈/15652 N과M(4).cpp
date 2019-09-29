#include<iostream>
using namespace std;
int N, M, ans[9];
void dfs(int index,int use)
{
	
	if (index == M)
	{
		for (int i = 0;i < M;i++)cout << ans[i]+1 << " ";
		cout << "\n";
		return;
	}
	
	for (int i = use;i < N;i++)
	{
		
			ans[index] = i;
			dfs(index + 1, i);

	
		
	}
}

int main()
{
	cin >> N >> M;
	dfs(0,0);
	return 0;

}