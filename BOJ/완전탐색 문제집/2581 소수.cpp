#include<cstdio>
#include<cstdlib>
#define MAX 1000000
int n, m;
int prime[MAX];
int arr[MAX];
int arr_size;
int flag;
void init()
{
	for (int i = 0;i < MAX;i++) prime[i] = 1;
	prime[0] = -1, prime[1] = -1;
}

void eratosthenes(int n,int arr[])
{
	init();
	for (int p = 2;p*p <= n;p++)
	{
		//if prime is not changed, then it is a prime
		if (prime[p] == 1)
		{
			//update all multiples of p
			for (int i = p * 2;i <= n;i += p) prime[i] = -1;
		}
	}
	int i = 0;
	for (int p = m;p <= n;p++)
	{
		
		if (prime[p] == 1)
		{
			flag = 1;
			arr[i] = p;
			i++;
		}
	}
	
	arr_size = i;

}

void print(int arr[],int size)
{
	for (int i = 0;i < size;i++)printf("%d ", arr[i]);
	printf("\n");
}

void solve()
{
	if (flag)
	{
		int sum = 0;
		for (int i = 0;i < arr_size;i++) sum += arr[i];
		printf("%d\n", sum);
		printf("%d\n", arr[0]);
	}
	else
		printf("-1\n");
	
}
int main()
{
	scanf("%d %d", &m,&n);
	eratosthenes(n,arr);
	solve();
	return 0;
}