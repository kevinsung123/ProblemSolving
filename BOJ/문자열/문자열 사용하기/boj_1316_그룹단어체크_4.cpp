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
		int check = 0; //�׷�ܾ� ���� �ƴ��� üũ���� check=0�̸� �׷�ܾ� check=1�̸� �׷�ܾ� �ƴ�
		for (int i = 0;i < strlen(input);i++)
		{
			//�̹� ���Դ� �����ε� �������ڿ� Ʋ���� check=1 && break;
			if (alpha[input[i] - 'a'] >=1 )
			{
				
				if (input[i] != input[i-1])
				{
					check = 1;
					break;
				}
				
			}
			//ó�� ������ �����̸� 1���� ī��Ʈ
			else alpha[input[i] - 'a'] += 1;
		}
		if (check == 0) cnt++;
		
	}
	printf("%d\n", cnt);
}