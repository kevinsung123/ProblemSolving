#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 100000
int d[MAX+10];
int a[110];
int N, K;
int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> a[i];
	fill(d, d + MAX+10, 1e9);
	d[0] = 0;
	for (int i = 0; i < N; i++)//동전 종류
	{
		
		d[a[i]] = 1;
		for (int j = 1; j <= K; j++)//만들려는 금액
		{
			if (j - a[i] >= 0)//만들려는 금액- 동전종류
			{
				d[j] = min(d[j], d[j - a[i]] + 1);
			}
		}
	}
	cout << (d[K]==1e9?-1:d[K]) << "\n";
}