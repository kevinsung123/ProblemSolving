#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
int match[20];
int cnt;
//idx= 사용된수의 개수, sum=합
bool dfs(int idx,int sum)
{
	if (sum > n) return false;
	if (sum == n)
	{
		cnt++;
		if (cnt == k)
		{
			for (int i = 0;i < idx-1;i++)cout << match[i] << "+";
			cout << match[idx - 1] << "\n";			
			return true;
		}
	}
	for (int i = 1;i <=3;i++)
	{
		match[idx] = i;
		if (dfs(idx + 1, sum + i)) return true; //중요!!
	}
	return false;
}
int main()
{
	cin >> n >> k;
	int flag = dfs(0, 0);
	if (flag == false) cout << -1 << "\n";
}