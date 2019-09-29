#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX_N = 4000000;
int main()
{
	
	int N;
	cin >> N;
	//scanf("%d", &N);
	bool isPrime[MAX_N];
	memset(isPrime, 1, sizeof(isPrime));
	vector<int> prime;
	for (int i = 2;i<= MAX_N;i++)
	{
		if (isPrime[i])
		{
			for (int p = 2 * i;p <= MAX_N;p += i) isPrime[p] = false;
		}
		if (isPrime[i]) prime.push_back(i);
	}
	int p1 = 0, p2 = 0, sum = 0, ans = 0;
	while (1)
	{
		if (sum >= N)sum -= prime[p1++];
		else if (p2 == prime.size()) break;
		else sum += prime[p2++];
		if (sum == N) ans++;
	}
	printf("%d\n", ans);
}