#include<cstdio>
#include<cstdlib>
int arr[101];
int n, cnt;

bool isPrime(int num)
{
	if (num == 1) return false;

	for (int j = 2; j*j< num;j++)
	{
		if (num % j == 0) return false;

	}
	return true;
}

void solve()
{
	for (int i = 0;i < n;i++)
	{
		if (isPrime(arr[i])) cnt++;
	}
}
int main()
{

	/*scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", &arr[i]);
	solve();
	printf("%d\n", cnt);*/
	while (1)
	{
		int num;
		scanf("%d", &num);
		if (isPrime(num)) puts("true");
		else puts("false");
	}
	return 0;

}