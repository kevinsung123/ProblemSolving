#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
typedef long long int ll;
using namespace std;
const int MAX_N = 4000000;
int prime[MAX_N + 10];
int sum[MAX_N + 1];
void eratosthenes()
{
	for (int i = 0;i <= MAX_N;i++) prime[i] = 1;
	prime[0] = -1, prime[1] = -1;
	for (int i = 2;i*i <= MAX_N;i++)
	{
		if (prime[i] == 1)
		{
			for (int p = 2 * i;p <= MAX_N;p += i) prime[p] = -1;
		}
	}

}
int main()
{
	int N;
	scanf("%d", &N);
	int idx = 1;
	eratosthenes();
	vector<int> factor;
	for (int i = 2;i <= N;i++)
	{
		if (prime[i] == 1)
		{
			factor.push_back(i);
			sum[idx] = sum[idx - 1] + i;
			idx++;
		}
	}
	int cnt = 0;
	int fact = 0;
	int p1 = 1, p2 = 1;
	int k = idx;

	//sum의 idx 1-size or 1-idx-1
	while (1)
	{	//p1-p2까지합
		if (sum[p2] - sum[p1 - 1] >= N) p1++;
		else if (sum[p2] - sum[p1 - 1] < N)
		{
			if (p2 < k - 1) p2++;
			else p1++;
		}
		if (sum[p2] - sum[p1 - 1] == N) cnt++;
		if (p1 - 1 == k) break;
	}
	printf("%d\n", cnt);
	return 0;
}