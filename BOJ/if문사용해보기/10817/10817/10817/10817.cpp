#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(void)
{
	int a, b, c, max;
	std::ios::sync_with_stdio(false);
	scanf("%d %d %d", &a, &b, &c);

	max = (a > b) ? (c > a ? a : (c > b ? c : b)) : (c > b ? b : a > c ? a : c);
	printf("%d", max);

	return 0;
}