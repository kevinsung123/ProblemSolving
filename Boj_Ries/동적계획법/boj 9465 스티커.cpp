#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000*10
typedef long long int ll;
ll a[2][MAX + 1];
ll d[2][MAX + 1];
int N;
ll solve(int row,int n)
{
	printf("row=%d n=%d\n", row, n);
	if (n == 1) return a[row][n];
	if (n == 2) return a[row][2] + a[(row + 1) % 2][1];
	if (d[row][n] != -1) return d[row][n];

	if (n >= 3)
	{
		if (row == 0)
		{
			return d[0][n] = max(solve(0, n - 2) + a[1][n - 1], solve(1, n - 2) + a[0][n]);
		}
		else if (row == 1)
		{
			return d[1][n] = max(solve(0, n - 2) + a[1][n], solve(1, n - 2) + a[0][n - 1]);
		}
	 }
		
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> a[0][i];
		for (int i = 1; i <= N; i++) cin >> a[1][i];
		memset(d, -1, sizeof(d));
		//cout << max(solve(0,N),solve(1,N)) << "\n";
		cout << solve(0, N) << "\n";
		cout << solve(1, N) << "\n";
	}
}