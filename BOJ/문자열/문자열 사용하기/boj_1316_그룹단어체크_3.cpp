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
		bool flag = true; //�׷�ܾ��̸� true �׷�ܾ� �ƴϸ� false
		check[input[0] - 'a'] = 1; // ù ���� check
		for (int i = 1;i < strlen(input);i++)
		{	//���� ���ڿ� ���� ���� ������� continue
			if (input[i] == input[i - 1]) continue;
			// ���� ���ڿ� ���� ���ڰ� Ʋ���ܿ� && check ���� 1�̻�
			if (check[input[i] - 'a'] > 0) flag = false;
			//check���� 0�̸� 1�� ���� ä����
			else check[input[i] - 'a'] = 1;
			
		}
		cnt += flag;

	}
	printf("%d\n", cnt);


}