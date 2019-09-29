#include<cstdio>
using namespace std;

int main(void)
{
	int sum = 0;
	int score = 0;

	for (int i = 0;i < 5;i++)
	{
		scanf("%d", &score);
		if (score < 40) score = 40;

		
		sum += score;
		//printf("sum=%d score=%d\n", sum, score);
	}
	printf("%d\n", sum / 5);
}