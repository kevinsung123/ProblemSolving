#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int arr[9];
int save[9];
int N, M;
int cnt;

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selection()
{
	int i, j, min;
	for (i = 0;i < N - 1;i++)
	{
		min = i;
		//최소값찾기
		for (j = i + 1;j < N;j++)
		{
			if (arr[j] < arr[min]) 
			{
				min = j;
				cnt++;
			}
		}
		swap(&arr[min], &arr[i]);
	}

}

void dfs(int idx)
{
	if (idx == M)
	{
		for (int i = 0;i < M;i++) printf("%d ", save[i]);
		puts("");
		return;
	}
	for (int i = 0;i < N;i++)
	{
		save[idx] = arr[i];
		dfs(idx + 1);
	}
}


int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0;i < N;i++) scanf("%d", &arr[i]);
	//for (auto i : arr)printf("%d ", i);puts("");
	//selection();
	
	sort(arr, arr + N);
	
	dfs(0);
}