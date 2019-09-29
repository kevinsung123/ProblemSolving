#include<cstdio>
#include<cstring>
using namespace std;

int main(void)
{
	int n, total;
	char input[100];
	int arr[26] = { 0, }; //알파벳 체크 
	int cnt = 0; //그룹단어 아닌단어 개수
	scanf("%d", &n);
	total = n;
	while(n--)
	{
		memset(input, 0, sizeof(input)); //초기화
		memset(arr, 0, sizeof(arr));
		scanf("%s", input); //단어 입력받기
		for (int i = 0;i < strlen(input);i++)
		{
		
			//arr 1인데 input이 또 들어오면 cnt 
			if (arr[input[i] - 'a'] == 1)
			{
				cnt++;
				break;
			}
			//arr 0이면 문자가 처음 들어올떄 -1로변경 체크중
			else if (arr[input[i] - 'a'] == 0 && input[i]==input[i+1]) arr[input[i] - 'a'] = -1;
			//arr 0이면서 다음문자와 틀리면 그룹단어 체크 끝 1로 변경
			else if (arr[input[i] - 'a'] == 0 && input[i] != input[i + 1]) arr[input[i] - 'a'] = 1;
			//arr  -1이면서 문자가 같으면 계속 -1
			else if ( arr[input[i] - 'a'] == -1 && input[i] == input[i + 1]) arr[input[i] - 'a'] = -1;
			//arr= -1이면서 다른 문자가 나오면 arr =1 
			else if (arr[input[i]-'a']==-1 && input[i] != input[i + 1]) arr[input[i] - 'a'] = 1; 
		}
		
		/*for (int i = 0;i < 26;i++)
			printf("%d ",arr[i]);
		printf("\n");
		printf("cnt=%d\n", cnt);

		*/
	}
	printf("%d\n", total - cnt);


}

