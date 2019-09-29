#include<iostream>
#include<cstring>
using namespace std;
const int MOD = 1e9;
typedef long long ll;
ll d[101][11];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	//d[N][i]=���̰� N�� ù�ڸ����� i�� ����Ǽ�
	for (int i = 1; i <=9; i++)d[1][i] = 1;

	for (int i = 2;i <= n; i++) //���̵Ǵ¼�
	{
		for (int j = 0; j <= 9; j++) //ù�����ڸ��� j�϶�
		{
			if (j == 0) d[i][j] = d[i - 1][1]%MOD;
			else if (j == 9) d[i][j] = d[i - 1][8]%MOD;
			else
			{
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % MOD;
			}
		}
	}
	ll sum = 0;
	for (int i = 0; i <= 9; i++)sum =(sum+ d[n][i])%MOD;

	cout << sum << "\n";
}