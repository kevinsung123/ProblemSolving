#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

#define MAX 1000000000

int main(void)
{
	int a, b, c, len = 0, temp;

	scanf("%d %d %d", &a, &b, &c);
	int sum = a * b*c;
	int cnt[10] = { 0 };
	temp = sum;

	//���� ���̸�ŭ �����Ҵ�
	do {
		sum = sum / 10;
		len++;
	} while (sum > 0);

	char * str = new char[len+1];
	//���ڸ� ���ڿ��� ��ȯ
	sprintf(str, "%d", temp);
	str[strlen(str)] = 0;  

	


	for (int i = 0; i < strlen(str);i++)
	{
		cnt[str[i]-'0']++;   //index�� ������ �����ϱ�!!! str[i]�� char�̹Ƿ� ���ڷ� �ٲ��־���Ѵ�.
	}

	for (int i = 0;i < 10;i++)
	{
		printf("%d\n", cnt[i]);
	}
}