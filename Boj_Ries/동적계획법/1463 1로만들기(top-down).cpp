#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int d[1000 * 1000 + 1];
int arr[1000 * 1000 + 1];
int N;
int dp(int x)
{
	if (x == 1) return 0;
	if (d[x] != -1) return d[x];
	int res = dp(x - 1) + 1;
	if (x % 2 == 0) res = min(res, dp(x / 2)+1);
	if (x % 3 == 0)  res = min(res, dp(x / 3)+1);
	return d[x] = res;

}
int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	memset(d, -1, sizeof(d));
	cout << dp(N) << "\n";
}