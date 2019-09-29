#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_N 100001
using namespace std;

int arr[MAX_N];
int pSum[MAX_N];

int main()
{
	int n, s, minLen = MAX_N, len = 0;
	int p1 = 1, p2 = 1;

	scanf("%d %d", &n, &s);

	// pSum�� ���� 1~i������ ���� ��Ÿ���ش�.
	for (int i = 1; i <= n; i++)
	{
		scanf(" %d", &arr[i]);

		pSum[i] = pSum[i - 1] + arr[i];
	}

	// p1�� p2�� ����, p1�� n�� ������ ��찡 �ƴ� ��쿡 while
	while (1)
	{
		if (pSum[p2] - pSum[p1 - 1] >= s)
		{
			len = p2 - (p1-1);
			minLen = min(minLen, len);
			p1++;
		}
		else if (pSum[p2] - pSum[p1 - 1] < s)
		{
			if (p2 < n)	p2++;
			else p1++;
		}
		if (n == p1 - 1) break;
	}

	// ���� ���
	if (minLen == MAX_N)
		cout << "0";
	else
		cout << minLen;

	return 0;
}


