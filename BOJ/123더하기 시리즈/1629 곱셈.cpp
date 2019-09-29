#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long int ll;
int A, B, C;
int cnt(int num)
{
	for (int i = 0;i <= 31;i++)
	{
		if (num & (1 << i)) return i;
	}
}
bool ispower(int n)
{
	return n && !( n&(n - 1));
}
ll power(int a, int b)
{
	if (b == 0) return 1;
	
	//b°¡ °ÅµìÁ¦°öÀÏ¶§
	if (ispower(b))
	{
		ll ret = a;
		for (int i = 0;i < cnt(b);i++)
			ret *= a;
		//printf("a=%d b=%d power %d\n", a, b, ret);
		return ret;

	}

	ll tmp;
	tmp = power(a, b / 2);
	ll ans = (tmp*tmp) % C;
	//b°¡ Â¦¼öÀÏ‹š
	if (b % 2 == 0)
	{
		//printf("a=%d b=%d ans=%d\n", a, b, ans);
		return ans;
	}
	//b°¡ È¦¼öÀÏ¶§
	else {
		
		ans = (ans*a) % C;
		//printf("a=%d b=%d ans=%d\n", a, b, ans);
		return ans;
	}
}

int main()
{
	
	scanf("%d %d %d", &A, &B, &C);
	printf("%lld\n", power(A, B));
}