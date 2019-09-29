#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAX = 1000001;
const int MOD = 1000000009;
int T, N;
ll cnt = 0;

ll dp[MAX];
void getNum()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4;i <= MAX;i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%MOD;
	}

}
int main()
{
	scanf("%d", &T);
	getNum();
	while (T--)
	{
		scanf("%d", &N);
		printf("%d\n",dp[N]);
	}

}