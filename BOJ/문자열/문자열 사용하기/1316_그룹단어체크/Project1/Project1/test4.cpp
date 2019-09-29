#include<cstdio>
#include<cstring>
int main(void)
{
	int t, cnt = 0;
	
	scanf("%d", &t);
	while (t--)
	{
		char input[101] = { 0, };
		int alpha[27] = { 0, };
		scanf("%s", input);
		int check = 0; //그룹단어 인지 아닌지 체크변수 check=0이면 그룹단어 check=1이면 그룹단어 아님
		for (int i = 0;i < strlen(input);i++)
		{
			//이미 나왔던 문자인데 이전문자와 틀리면 check=1 && break;
			if (alpha[input[i] - 'a'] >=1 )
			{
				
				if (input[i] != input[i-1])
				{
					check = 1;
					break;
				}
				
			}
			//처음 나오는 문자이면 1개씩 카운트
			else alpha[input[i] - 'a'] += 1;
		}
		if (check == 0) cnt++;
		
	}
	printf("%d\n", cnt);
}