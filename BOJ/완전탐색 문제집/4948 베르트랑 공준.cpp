#include<cstdio>
#include<cstdlib>
#define MAX 150000
int n, cnt;
int prime[2*MAX];
void eratosthenes()
{
	//-1 false 0 true
	prime[0] = -1, prime[1] = -1;
	for (int p = 2;p*p <= 2 * MAX;p++)
	{
		if (prime[p] == 0)
		{
			for (int i = 2 * p;i <= 2 * MAX;i += p) prime[i] = -1;
		}
	}
	
}
int main()
{
	
	while (true)
	{
		
		scanf("%d", &n);
		if (n == 0) break;
		eratosthenes();
		cnt = 0;
		for (int i = n+1;i <= 2 * n;i++)
		{
			if (prime[i] == 0) cnt++;
		}
		printf("%d\n", cnt);
	}
}