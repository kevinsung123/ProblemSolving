#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std; 
int N, M;
int arr[9], save[9];
void dfs(int idx,int use)
{
	if (idx == M)
	{
		for (int i = 0;i < M;i++)printf("%d ", save[i]);
		puts(" ");
		return; //ÀØÁö¸»ÀÚ!!
	}

	for (int i = use;i < N;i++)
	{
		save[idx] = arr[i];
		dfs(idx + 1, i);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0;i < N;i++)scanf("%d", &arr[i]);
	sort(arr, arr + N);
	dfs(0,0);
}