#include<cstdio>

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++)
	{
		int k = 0;
		while (k != i)
		{
			k++;
			printf("*");
		}
		printf("\n");
	}
	
}