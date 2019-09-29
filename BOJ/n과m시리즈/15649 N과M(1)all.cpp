#include<vector>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<cstdio>
using namespace std;
bool visited[8];
int ans[8];
int N, M;
int a[9];
//채울 index
void dfs(int index)
{
	if (index == M)
	{
		for (int i = 0;i < M;i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	//1부터 N까지 사용
	for (int i = 1;i <= N;i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			ans[index] = i;
			dfs(index + 1);
			visited[i] = false;
		}
	}
}
void bin(int vis)
{
	unsigned i;
	for (i = 1 << 31;i > 0;i /= 2)
		(vis&i) ? printf("1") : printf("0");
	cout << "\n";
}

void func(int cur, int vis)
{
	cout << "cur=" << cur;
	cout << " vis=";
	bin(vis);
	cout << "\n";
	if (cur == M)
	{
		for (int i = 0;i < M;i++)
			cout << a[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1;i <= N;i++)
	{
		if (!(vis&(1 << i)))
		{
			a[cur] = i;
			func(cur + 1, vis | (1 << i));
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	//dfs(0);
	func(0, 0);
	/*for (int i = 0;i <= N;i++)
		bin(1 << i);*/
}