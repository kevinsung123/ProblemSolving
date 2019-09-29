#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, S, E;
int d[2002][2002];
int arr[2002];

int palindrome(int low, int high)
{
	if (low > high) return 1;  //숫자1개일떄
	int &ret = d[low][high];
	if (ret != -1) return ret;
	if (arr[low] != arr[high]) return 0;

	return ret = palindrome(low + 1, high - 1);
}

int main()
{
	scanf("%d", &N);
	memset(d, -1, sizeof(d));
	for (int i = 1;i <= N;i++) scanf("%d", &arr[i]);
	palindrome(0, N - 1);
	scanf("%d", &M);
	for (int i = 0;i < M;i++)
	{
		scanf("%d %d", &S, &E);
		if (d[S][E]) puts("1");
		else puts("0");

	}
}