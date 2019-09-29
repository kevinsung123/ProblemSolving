#include<iostream>
#include<cstring>
using namespace std;
#define MOD 15746
#define MAX 1000000
//int d[MAX + 1];
//int tile(int n)
//{
//	if (n == 1) return 1;
//	if (n == 2) return 2;
//	if (d[n] != -1) return d[n];
//
//	int res = (tile(n - 1)+tile(n - 2)) % MOD;
//	d[n] = res%MOD;
//	return d[n];
//}

int main()
{
	int N;
	cin >> N;
	/*d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		d[i] = (d[i - 1] + d[i - 2] ) % MOD;
	}*/
	//memset(d, -1, sizeof(d));
	//cout << tile(N) << "\n";
	int a, b, c;
	a = 1, b = 2, c;
	for (int i =3 ; i <= N; i++)
	{
		c = (a + b) % MOD;
		a = b, b = c;
	}
	cout << c << "\n";
}