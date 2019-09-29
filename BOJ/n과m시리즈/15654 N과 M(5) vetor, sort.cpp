#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> res;
vector<bool> check;
int N, M;
int  save[9];

void dfs(int index)
{
	if (index == M)
	{
		for (int i = 0;i < M;i++)cout << save[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0;i < N;i++)
	{
		if (!check[i])
		{
			check[i] = true;
			save[index] = res[i];
			dfs(index + 1);
			check[i] = false;
		}
	}
}
int main()
{
	cin >> N >> M;
	check.resize(N + 1,false);
	for (int i = 0;i < N;i++)
	{
		int temp;
		cin >> temp;
		res.push_back(temp);
	}
	sort(res.begin(), res.end());
	dfs(0);
}