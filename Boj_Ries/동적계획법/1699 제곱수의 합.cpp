#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAX 100000
int d[MAX + 1];
int main()
{
	int N;
	cin >> N;
	fill(d, d + MAX + 1, 1e9);
	d[0] = 0;
	for (int i = 1; i*i <= N; i++)//제곱수
	{
		for (int j = i*i; j <= N; j++)//만들려는합
		{
			if (j - i * i >= 0)
			{
				d[j] = min(d[j], d[j - i * i] + 1);
			}
		}
	}
	cout << d[N] << "\n";
}