/* char 배열으로 문제해결방법*/
#include<cstdio>
#include<cstring>
using namespace std;


int main(void)
{
	int num = 0;
	int score = 0;
	char str[82];
	int c;
	scanf("%d", &c);
	while (c--)
	{
		score = 0;
		num = 0;
		scanf("%s", str);
		for (int i = 0;i < strlen(str);i++)
		{
			if (str[i] == 'x' || str[i] == 'X')
			{
				num = 0;
			}
			else
			{
				num++;
			}
			score += num;
		}
		printf("%d\n", score);
	}


}
