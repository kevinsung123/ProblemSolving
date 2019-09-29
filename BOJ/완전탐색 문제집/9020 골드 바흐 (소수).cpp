#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
int prime[10002];
int T, N;

void eratosthenes()
{
	prime[0] = -1, prime[1] = -1;
	for (int p = 2;p*p <= 10000;p++)
	{
		if (prime[p] == 0)
		{
			for (int i = 2 * p;i <= 10000;i += p) prime[i] = -1;
		}
	}
}
int main()
{
	scanf("%d", &T);
	eratosthenes();
	while (T--)
	{
		scanf("%d", &N);
		for (int i = N / 2;i>=2;i--)
		{
			if (prime[i] == 0 && prime[N-i]==0)
			{
				
				printf("%d %d\n", i, N - i);
				break;
			}
		}
	}
}