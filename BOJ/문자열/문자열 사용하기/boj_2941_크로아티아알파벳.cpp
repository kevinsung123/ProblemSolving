#include<cstdio>
#include<cstring>

int main(void)
{

	char input[101] = { 0 };
	scanf("%s", input);
	int cnt = 0;
	for (int i = 0;i < strlen(input);i++)
	{
		cnt++;
		if (input[i] == '=')
		{
			if (input[i - 1] == 's' || input[i - 1] == 'z' || input[i - 1] == 'c' || input[i - 1] == 'z')
			{
				if (input[i - 2] == 'd')
					cnt--;
				cnt--;
			}
		}

		if (input[i] == '-')
		{
			if (input[i - 1] = 'c' || input[i - 1] == 'd')
			{
				cnt--;
			}
		}

		if (input[i] == 'j')
		{
			if (input[i - 1] == 'l' || input[i - 1] == 'n')
				cnt--;
		}
	}

	printf("%d\n", cnt);

}