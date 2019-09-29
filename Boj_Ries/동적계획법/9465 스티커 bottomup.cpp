#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 100000
int a[2][MAX+1];
int d[2][MAX+ 1];
int T;
int N;
int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> N;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= N; i++) cin >> a[0][i];
		for (int i = 1; i <= N; i++) cin >> a[1][i];
		d[0][0] = d[1][0] = 0;
		d[1][1] = a[1][1];
		d[0][1] = a[0][1];
		for (int i = 2; i <= N; i++)
		{
			d[0][i] = max(d[1][i - 1], d[1][i - 2]) + a[0][i];
			d[1][i] = max(d[0][i - 1], d[0][i - 2]) + a[1][i];
		}
		cout << max(d[0][N], d[1][N])<< "\n";
	}
}