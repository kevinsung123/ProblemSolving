//#include<iostream>
//using namespace std;
//
//int N, M;
//int A[8] = { 1,2,3,4,5,6,7 };
//
//void print_arr(int *A, int m)
//{
//	for (int i = 0;i < m;i++)
//		cout << A[i] << " ";
//	cout << endl;
//}
//
//void swap(int i, int index, int *A)
//{
//	int temp = A[i];
//	A[i] = A[index];
//	A[index] = temp;
//}
//void perm(int *A,int depth, int n, int m)
//{
//	if (depth == m)
//	{
//		print_arr(A, m);
//	}
//
//	for (int i = depth;i < n;i++)
//	{
//		swap(i, depth, A);
//		perm(A,  depth + 1, n, m);
//		swap(i, depth, A);
//	}
//}
//
//int main(void)
//{
//	cin >> N >> M;
//
//
//	perm(A, 0, N, M);
//	
//}

#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
bool visited[8];
int res[8];
void dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0;i < M;i++)
			cout << res[i] << " ";
		cout << endl;
		return;
	}

	for (int i = 0;i < N;i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			res[cnt] = i + 1;
			dfs(cnt + 1);
			visited[i] = 0;
		}
	}
}
int main(void)
{
	cin >> N >> M;
	dfs(0);
}