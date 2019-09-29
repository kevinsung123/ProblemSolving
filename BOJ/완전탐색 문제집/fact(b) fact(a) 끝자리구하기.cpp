#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{
	ll a, b, tmp;
	scanf("%lld %lld", &a, &b);
	tmp = 1;
	for (ll i = a + 1;i <= b;i++)
	{
		tmp = (i % 10)*tmp;
		tmp %= 10;
		if (tmp == 0)break;
	}
	printf("%d\n", tmp);
}