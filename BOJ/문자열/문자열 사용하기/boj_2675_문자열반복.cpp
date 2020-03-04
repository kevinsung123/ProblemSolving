//char 배열로 문제 해결 
//첫번째 틀린원인은 초기화를 매 test case 마다 해주어야함
//두번쨰 풀떄는 새로 배열에 값을 넣기보다는 바로바로 출력해주기!
#include<cstring>
#include<cstdio>

int main(void)
{
	char s[20];
	char t[300];
	
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(t, 0, sizeof(t));
		int r, k = 0;
		scanf("%d %s",&r,s);
		for (int i = 0;i < strlen(s); i++)
		{
			for (int m = 0;m < r;m++)
			{
				t[k++] = s[i];
			}
		}
		printf("%s\n", t);
	}
}