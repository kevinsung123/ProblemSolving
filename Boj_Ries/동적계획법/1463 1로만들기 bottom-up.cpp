#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000*1000
int d[MAX+ 1];
int N;

int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	fill(d, d + MAX + 1, 1e9);
	d[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		d[i] = d[i - 1] + 1;
		if(i%2==0) d[i] = min(d[i], d[i/2]+1);
		if(i%3==0) d[i] = min(d[i], d[i/3]+1);

	}
	cout << d[N] << "\n";
}