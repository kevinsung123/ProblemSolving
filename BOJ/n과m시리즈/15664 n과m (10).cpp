#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num[11];
int n, m;
int check[11];
int match[11];


void perm(int idx,int use)
{
	if (idx == m)
	{
		for (int i = 0;i < m;i++)cout << match[i] << " ";
		cout << "\n";
		return;
	}
	int prev = 0;
	for (int i =use;i < n;i++)
	{
		if (!check[i] && prev!=num[i])
		{
			check[i] = true;
			match[idx] = num[i];
			perm(idx + 1, i);
			prev = num[i];
			check[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++) cin >> num[i];
	sort(num, num + n);
	perm(0, 0);
	return 0;
}