#include<cstdio>
const int MOD = 10007;
int d[1001];


int dp(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 3;
	if (d[x]!=0) return d[x];
	
	//값을 저장하면 리턴!!
	return d[x] = (dp(x - 1) + dp(x - 2) * 2) % MOD;
}


int main()
{
	int n;
	scanf(" %d", &n);
	printf("%d", dp(n));
}