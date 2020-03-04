#include<cstdio>
using namespace std;

int main(void)
{

	int num[8];
	int asc = 0;
	int dsc = 0;
	for (int i = 0;i < 8;i++)
	{
		scanf("%d", &num[i]);
		if (num[i] == i + 1) asc++;
		else if (num[i] == 8 - i) dsc++;
	}

	if (asc == 8) printf("ascending\n");
	else if (dsc == 8) printf("descending\n");
	else printf("mixed\n");
}