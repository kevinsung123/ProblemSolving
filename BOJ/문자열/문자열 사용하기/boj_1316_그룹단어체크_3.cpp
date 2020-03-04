#include<cstdio>
#include<cstring>

int main(void)
{
	int check[27] = { 0 , };
	char input[101] = { 0 , };
	int cnt = 0;
	int t;

	scanf("%d", &t);
	while (t--)
	{
		memset(check, 0, sizeof(check));
		memset(input, 0, sizeof(input));
		scanf("%s", input);
		bool flag = true; //그룹단어이면 true 그룹단어 아니면 false
		check[input[0] - 'a'] = 1; // 첫 문자 check
		for (int i = 1;i < strlen(input);i++)
		{	//이전 문자와 현재 문자 같은경우 continue
			if (input[i] == input[i - 1]) continue;
			// 이전 문자와 현재 문자가 틀린겨우 && check 값이 1이상
			if (check[input[i] - 'a'] > 0) flag = false;
			//check값이 0이면 1로 값을 채워줌
			else check[input[i] - 'a'] = 1;
			
		}
		cnt += flag;

	}
	printf("%d\n", cnt);


}