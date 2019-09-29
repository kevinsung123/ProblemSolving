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

	// pSum은 구간 1~i까지의 합을 나타내준다.
	for (int i = 1; i <= n; i++)
	{
		scanf(" %d", &arr[i]);

		pSum[i] = pSum[i - 1] + arr[i];
	}

	// p1과 p2가 같고, p1이 n에 도달한 경우가 아닌 경우에 while
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

	// 정답 출력
	if (minLen == MAX_N)
		cout << "0";
	else
		cout << minLen;

	return 0;
}


