#include<iostream>
#include<vector>
#include<algorithm>
int arr[20];
bool check[20];
int ans, n, sum;
int a, b;
//а╤гу!
void dfs(int idx, int use,int tot)
{
	a++;
	printf("%d %d %d \n", idx, use, tot);
	if (idx > n) return;
	if(tot==sum && idx>0)
	{
		ans++;
	}
	for (int i = use;i < n;i++)
	{
		if (!check[i])
		{
			check[i] = true;
			dfs(idx + 1, i + 1, tot + arr[i]);
			check[i] = false;
		}
	}
}

void solve(int idx, int tot)
{
	b++;
	printf("%d %d\n", idx, tot);
	if (idx >= n) return;

	if (tot + arr[idx] == sum) ans++;

	solve(idx + 1, tot);
	solve(idx + 1, tot + arr[idx]);
}

int main()
{

	scanf("%d %d", &n, &sum);
	for (int i = 0;i < n;i++)scanf("%d", &arr[i]);
	dfs(0, 0, 0);
	printf("%d\n", ans);
	ans = 0;
	solve(0, 0);
	printf("%d\n", ans);
	printf("a=%d b=%d\n", a, b);
}