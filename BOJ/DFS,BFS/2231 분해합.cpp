#include<iostream>
#include<cstdio>
#include<cmath>
int main()
{
	int n;
	scanf("%d", &n);
	
	int min = 1e9;
	for (int i = n;i> n-55;i--)
	{
		int check = i;
		int sum = check;
		//각자리수 더하기
		while (check)
		{
			sum += (check % 10);
			check /= 10;
		}
		if (sum == n)
		{
			min = min > i ? i : min;
		}
	}
	if (min == 1e9) min = 0;
	printf("%d\n", min);
}