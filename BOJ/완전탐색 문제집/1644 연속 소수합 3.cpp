#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX_N = 4000000;

int main()
{
	int N;
	scanf("%d", &N);
	int prime[MAX_N];
	int sum[MAX_N];  //메모리초과..
	vector<int> factor;
	memset(prime, 1, sizeof(prime));
	for (int i = 2;i <= MAX_N;i++)
	{
		if (prime[i] == 1)
		{
			for (int p = 2 * i;p <= MAX_N;p += i) prime[p] = -1;
		}
		if (prime[i]) factor.push_back(i);
	}
	for (int i = 0;i <factor.size();i++)
	{
		if (i == 0) sum[i + 1] = factor[i];
		else sum[i + 1] = sum[i] + factor[i];
	}
	for (auto x : sum)
		cout << x << " ";
	int p1 = 1, p2 = 1, cnt = 0;
	while (!(p1 > p2 && p1 == factor.size()))
	{
		if (sum[p2] - sum[p1 - 1] >= N) p1++;
		else if (sum[p2] - sum[p1 - 1] < N)
		{
			if (p2 < factor.size()) p2++;
			else p1++;
		}
		if (sum[p2] - sum[p1 - 1] == N)
		{
			cnt++;
			printf("p1-1=%d,p1=%d, p2=%d sum=%d\n", p1 - 1, p1, p2,sum[p2]-sum[p1-1]);
		}

	}
	printf("%d\n", cnt);
	return 0;
}