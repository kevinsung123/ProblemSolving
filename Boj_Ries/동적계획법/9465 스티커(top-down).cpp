#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
int a[2][100000];
ll d[2][100000];
int T;
int N;
ll dp(int r,int c)
{
	//cout << r << "," << c <<"="<<a[r][c]<< "\n";
	if (r < 0 || c < 0) return 0;
	if (c == 1) return a[r][c];
	if (d[r][c] != -1) return d[r][c];

	
	if (r == 0)
	{
		return d[0][c] = max(dp(1, c - 2),  dp(1, c - 1))+a[0][c];
	}
	else if (r == 1)
	{
		return d[1][c] = max(dp(0, c - 2), dp(0, c - 1)) + a[1][c];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> a[0][i];
		for (int i = 1; i <= N; i++)cin >> a[1][i];
		memset(d, -1, sizeof(d));
		d[0][0] = d[1][0] = 0;
		cout << max(dp(0, N), dp(1, N)) << "\n";
	}
}