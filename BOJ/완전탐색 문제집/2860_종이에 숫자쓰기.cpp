#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll gcd(ll a, ll b)
{
	if (a == 0) return b;
	return gcd(b%a, a);
}
int main(void)
{
	char P[12];
	scanf("%s", P);
	ll a = P[0] - '0';
	ll b = 1;
	for (int i = 2;i < P[i];i++)
	{
		a = a * 10 + P[i] - '0';
		b *= 10;
	}
	ll q = a / b;
	ll m = a - b * q;
	ll n = b;
	int g = gcd(m, n);
	m /= g;
	n /= g;
	int ans[7] = { 0, };
	ans[q] = n - m;
	ans[q + 1] = m;
	
	for (int i = 1;i <= 5;i++)
		printf("%d ", ans[i]);
	printf("\n");

}
