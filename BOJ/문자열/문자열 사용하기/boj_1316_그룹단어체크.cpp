#include<cstdio>
#include<cstring>
using namespace std;

int main(void)
{
	int n, total;
	char input[100];
	int arr[26] = { 0, }; //���ĺ� üũ 
	int cnt = 0; //�׷�ܾ� �ƴѴܾ� ����
	scanf("%d", &n);
	total = n;
	while(n--)
	{
		memset(input, 0, sizeof(input)); //�ʱ�ȭ
		memset(arr, 0, sizeof(arr));
		scanf("%s", input); //�ܾ� �Է¹ޱ�
		for (int i = 0;i < strlen(input);i++)
		{
		
			//arr 1�ε� input�� �� ������ cnt 
			if (arr[input[i] - 'a'] == 1)
			{
				cnt++;
				break;
			}
			//arr 0�̸� ���ڰ� ó�� ���Ë� -1�κ��� üũ��
			else if (arr[input[i] - 'a'] == 0 && input[i]==input[i+1]) arr[input[i] - 'a'] = -1;
			//arr 0�̸鼭 �������ڿ� Ʋ���� �׷�ܾ� üũ �� 1�� ����
			else if (arr[input[i] - 'a'] == 0 && input[i] != input[i + 1]) arr[input[i] - 'a'] = 1;
			//arr  -1�̸鼭 ���ڰ� ������ ��� -1
			else if ( arr[input[i] - 'a'] == -1 && input[i] == input[i + 1]) arr[input[i] - 'a'] = -1;
			//arr= -1�̸鼭 �ٸ� ���ڰ� ������ arr =1 
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

