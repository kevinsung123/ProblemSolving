#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int  res[9];
int  check[9];
int N, M;
int  save[9];

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selectionSort()
{
	int i, j, min;
	for (i = 0;i < N - 1;i++)
	{
		//printf("i=%d\n", i);
		min = i;
		//printf("min=%d\n", min);
		for (j = i + 1;j < N;j++)
		{
			//printf("j=%d ", j);
			if (res[min] > res[j])min = j;
		}
		//puts("\n");
		swap(&res[i], &res[min]);
		
	}


}

int partition(int low, int high)
{
	int pivot = res[high];
	int i = low - 1;
	for (int j = low;j <= high - 1;j++)
	{
		if (res[j] <= pivot)
		{
			++i;
			swap(&res[j], &res[i]);
		}
	}
	//i index까지 pivot보다 작고 그다음 pivot 위치
	swap(&res[i + 1], &res[high]);
	return i + 1;
}
void quicksort(int low, int high)//최소 최대 index
{
	if (low < high)
	{
		int pivot = partition(low, high);
		quicksort(low, pivot - 1);
		quicksort(pivot + 1, high);
	}
}
void dfs(int index)
{
	if (index == M)
	{
		for (int i = 0;i < M;i++)cout << save[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0;i < N;i++)
	{
		if (!check[i])
		{
			check[i] = true;
			save[index] = res[i];
			dfs(index + 1);
			check[i] = false;
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		cin >> res[i];
	}
	
	
	//selectionSort();
	quicksort(0, N - 1);
	/*for (int i = 0;i < N;i++)cout << res[i] << " ";
	 cout<<"\n";*/
	dfs(0);
}

//void swap(int *a, int * b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void selection()
//{
//	int i, j, min;
//	for (i = 0;i < N-1;i++)
//	{
//		min = i;
//		//최소값을 찾음
//		for (j = i+1;j < N;j++)
//		{
//			if (res[min] > res[j]) min = j;
//		}
//		swap(&res[min], &res[i]);
//	}
//}
//
//int partition(int low, int high)
//{
//	int pivot = res[high];
//
//	int i = low - 1;
//	
//	for (int j = low;j <= high - 1;j++)
//	{
//		if (res[j] <= pivot)
//		{
//			i++;
//			swap(&res[i], &res[j]);
//			
//			
//		}
//	}
//	swap(&res[i+1], &res[high]);
//	
//	return i+1;
//	
//
//}
//
//void quicksort(int low, int high)
//{
//	if (low < high)
//	{
//		int pivot = partition(low, high);
//		quicksort(low, pivot - 1);
//		quicksort(pivot+1, high);
//	}
//}
//