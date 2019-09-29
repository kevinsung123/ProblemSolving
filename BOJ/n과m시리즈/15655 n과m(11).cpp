#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num[11];
int n, m;
int check[11];
int match[11];


void multiperm(int idx)
{
	if (idx == m)
	{
		for (int i = 0;i < m;i++)cout << match[i] << " ";
		cout << "\n";
		return;
	}
	int prev = 0;
	for (int i = 0;i < n;i++)
	{
		if ( prev != num[i])
		{
		
			match[idx] = num[i];
			multiperm(idx + 1);
			prev = num[i];
			
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++) cin >> num[i];
	sort(num, num + n);
	multiperm(0);
	return 0;
}