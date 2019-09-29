#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define MAX 9
bool visited[MAX];
int ans[MAX];
set <vector<int>> st;
vector<int> res;
int n, m;
int main()
{
	cin >> n >> m;
	vector<int> perm;
	vector<int> bitmask;
	for (int i = 1;i <= n;i++) perm.push_back(i);
	for (int i = 0;i < m;i++) bitmask.push_back(0);
	for (int i = 0;i < perm.size() - m;i++)bitmask.push_back(1);
	sort(bitmask.begin(), bitmask.end());
	do
	{
		for (int i = 0;i < bitmask.size();i++)
		{
			if (bitmask[i] == 0)
				cout << perm[i] << " ";
			
		}
		cout << "\n";

	} while (next_permutation(bitmask.begin(), bitmask.end()));
}


