#include<cstdio>
#include<cstdlib>
int N, M;
int arr[9];
int save[9];
int check[9];

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low;j <= high - 1;j++)
	{
		if (arr[j] <= pivot)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}
void quicksort(int low, int high)
{
	if (low < high)
	{
		int pivot = partition(low, high);
		quicksort(low, pivot - 1);
		quicksort(pivot + 1, high);
	}
}

void bubble()
{
	int i, j;
	bool flag;
	for (i = 0;i < N - 1;i++)
	{
		flag = false;
		for (int j = 0;j < N - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				flag = true;
			}

		}
		//inner loop end
		if (!flag) break;
	}
}

void dfs(int idx, int use)
{
	if (idx == M)
	{
		for (int i = 0;i < M;i++)printf("%d ", save[i]);
		puts("");
	}
	for (int i = use;i < N;i++)
	{
		if (!check[i])
		{
			check[i] = 1;
			save[idx] = arr[i];
			dfs(idx + 1, i + 1);
			check[i] = 0;
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0;i < N;i++) scanf("%d", &arr[i]);
	//quicksort(0, N - 1);
	bubble();
	//for (auto i : arr) printf("%d ", i);
	puts("");
	dfs(0, 0);


}