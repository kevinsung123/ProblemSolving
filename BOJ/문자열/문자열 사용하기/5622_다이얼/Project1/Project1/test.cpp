#include<cstdio>
#include<cstring>

int main(void)
{
	char input[20] = { 0 }; //���� �Է� �迭
	int arr[8] = { 0 }; //��ȣ������ �ð��迭
	for (int i = 0;i < 8;i++)
		arr[i] = i + 3;  //��ȣ������ �ð� ���� �迭 �ʱ�ȭ
	int cnt = 0; //�� �ɸ��ð�
	scanf("%s", input);
	for (int i = 0;i < strlen(input);i++)
	{
		if (input[i] - 'A' == 18) cnt += arr[5];
		else if(input[i] - 'A' == 21)cnt += arr[6];
		else if (input[i] - 'A' == 24 || input[i]-'A'==25)cnt += arr[7];
		else  cnt += arr[(input[i] - 'A') / 3];
	}
	printf("%d\n", cnt);

}