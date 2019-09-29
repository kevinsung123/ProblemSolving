#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int m;
		scanf("%d", &m);
		double ans = 0.0;
		for (double i = (double)m;i > 0;i--)
		{
		//	printf("%f ",log10(i));
			ans += log10(i);
		}
		printf("%d\n", (int)ans+1);
	}
}