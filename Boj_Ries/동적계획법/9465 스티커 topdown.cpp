#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
int a[2][100000];
int d[3][100000];
int T;
int N;
int dp(int status, int c)
{
	if (c ==N ) return 0;
	if (d[status][c] != -1) return d[status][c];
	int res = dp(0, c+1); //¿ÞÂÊ¿­ ¾È¶ÂÀ»‹š
	if (status != 1) res = max(res, dp(1, c + 1) + a[0][c]);  //¿ÞÂÊ ¾Æ·¡ ŒHÀ»¶§
	if (status != 2) res = max(res, dp(2, c + 1) + a[1][c]); //¿ÞÂÊ À§ ¶ÂÀ»‹š
	return	d[status][c] = res;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++) cin >> a[0][i];
		for (int i = 0; i < N; i++) cin >> a[1][i];
		memset(d, -1, sizeof(d));
		
		cout <<dp(0, 0) << "\n";
	}
}