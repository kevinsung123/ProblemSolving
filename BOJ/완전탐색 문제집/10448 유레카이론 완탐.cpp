#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long int ll;
int T, K;
int d[1005];
int main()
{

	int i;
	for (i = 1;i*(i + 1) / 2 <= 1000; i++) d[i] = i*(i + 1)/2;
	int M = i;
	cin >> T;
	while (T--)
	{
		cin >> K;
		int ans = 0;
		int a, b, c;
		for (a = 1;a <= 45;a++)
		{
			for (b= 1;b <= 45;b++)
			{
				for (c= 1;c <= 45;c++)
				{
					if ( d[a] + d[b] + d[c] == K)
					{
						ans = 1;
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	
}