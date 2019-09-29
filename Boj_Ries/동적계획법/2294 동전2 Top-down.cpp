#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 10000
int d[102][MAX+1];
int a[110];
int N, K;

int coin(int n, int k)
{
	if (n == N) return (k==0?0:1e9);  //base case  동전 종류는 0-N-1까지만 있따
	if (d[n][k] != -1) return d[n][k]; //memoziation

	int res = coin(n + 1, k);
	//합k가 n번쨰 동전보다 크다면
	if (k >= a[n]) res = min(res, coin(n, k - a[n]) + 1);
	
	return d[n][k] = res;
	


}
int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> a[i];
	memset(d, -1, sizeof(d));
	int tmp = coin(0, K);
	if (tmp == 1e9) puts("-1");
	else cout << tmp << "\n";
	
}