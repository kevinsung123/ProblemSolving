#include<cstdio>
using namespace std;

int main(void)
{
	int n, x, temp, target;
	scanf("%d %d", &n, &x);
	while (n--)
	{
		scanf("%d ", &temp);
		if (temp < x) printf("%d ", temp);
	}
	
	return 0;
}