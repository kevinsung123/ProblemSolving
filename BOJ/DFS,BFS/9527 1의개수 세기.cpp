#include<stdio.h>
typedef long long int ll;

int cntBit(ll num)
{
	int cnt = 0;
	while (num)
	{
		cnt += (num & 1);
		num >>= 1;
	}
	return cnt;
}
int cntRecur(int n)
{
	if (n == 0)
		return 0;
	else
		return (n & 1) + cntRecur(n >> 1);
}
int main()
{
	ll a, b;
	scanf("%lld %lld", &a, &b);

	int sum = 0;
	for (ll i = a;i <= b;i++)
	{
		printf("%d\n", cntBit(i));
		sum += cntBit(i);
	}
	printf("%d\n", sum);
}