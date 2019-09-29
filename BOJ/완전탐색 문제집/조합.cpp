#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr(100, 0);
vector<int> temp;
int match[100];
int check[100];
int n, r;

void bin(int x)
{
	for (int i = 8;i >= 0;i--)
	{
		x&(1 << i) ? printf("1") : printf("0");
	}
	puts("");
}

void dfs(int idx, int prev)
{
	if (idx == r)
	{
		for (int i = 0;i < r;i++)printf("%d ", match[i]);
		puts("");
		return;
	}
	for (int i = prev;i < n;i++)
	{
		if (!check[i])
		{
			check[i] = 1;
			match[idx] = arr[i];
			dfs(idx + 1,i+1);
			check[i] = 0;
		}
	}
}



int main()
{

	scanf("%d %d",&n, &r);
	
	for (int i = 0;i < n;i++) arr[i] = i + 1;
	for (int i = 0;i < r;i++) temp.push_back(0);
	for (int i = 0;i < n - r;i++)temp.push_back(1);
	sort(temp.begin(), temp.end());
	puts("next_permutation");
	do {
		for (int i = 0;i < temp.size();i++)
		{
			if (temp[i] == 0)
			{
				printf("%d ", arr[i]);
			}
		}
		puts("");
	} while (next_permutation(temp.begin(), temp.end()));
	puts("dfs");
	dfs(0,0);
	puts("bitmask subset");
	for (int check = 0;check < (1 << n);check++)
	{
		bin(check);
	}
}