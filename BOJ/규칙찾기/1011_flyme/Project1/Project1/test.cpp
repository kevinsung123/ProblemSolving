#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long distance;
		long long cnt = 0;
		long long n;
		long long x, y;
		long long rest = 0;
		scanf("%lld %lld",&x,&y);
		distance = y - x;
		for (n = 0; n*n <= distance;n++) ;
		//printf("%d\n", n);
		rest = distance - (n-1)*(n-1);
	//	printf("%f\n", (double)rest / n);
		//printf("n=%lld, rest=%lld 올림=%lld\n",n-1,rest, (long long)ceil((double)rest / (n-1)));
		printf("%lld\n", 2*(n-1)-1+(long long)ceil((double)rest/(n-1)));  //ceil 반형이 double이므로 long long 

	}
	
}