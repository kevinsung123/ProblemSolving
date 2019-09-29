#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll a, b, tmp;
ll n;
ll cnt;
int main()
{
	scanf("%lld", &n);

	//n에서 5의개수를 찾는문제나 마찬가지다
	//2와 5의개수를 구해 둘중 작은수 
	int five = 0, two = 0;
	for (int i = 1;i <= n;i++)
	{
		tmp = i;
		while (tmp)
		{
			if (tmp % 2 == 0)
			{
				two++;tmp /= 2;
			}
			else break;
		}
		tmp = i;
		while (tmp)
		{
			if (tmp % 5 == 0)
			{
				five++;tmp /= 5;
			}
			else break;
		}
	}
	printf("%d\n", min(two, five));

	//5의 제곱으로 계속하여 5의개수를 알아낸다

	for (int i = 5;i <= n;i *= 5)
		cnt += n / i;
	printf("%d\n", cnt);
}