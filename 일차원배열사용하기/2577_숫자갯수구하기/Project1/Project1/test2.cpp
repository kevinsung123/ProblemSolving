#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

#define MAX 1000000000

int main(void)
{
	ios::sync_with_stdio(false);
	int a, b, c, len = 0;
	cin >> a >> b >> c;
	int sum = a * b*c;
	int cnt[10] = { 0 };
	
	
	
	
	//���� ���̸�ŭ �����Ҵ�
	do {
		sum = sum / 10;
		len++;
	} while (sum < 0);

	
	char * str = new char[len];

	//���ڸ� ���ڿ��� ��ȯ
	itoa(sum, str, 10);

	for (int i = 0;i < strlen(str);i++)
	{
		cnt[str[i]]++;
		
	}

	for (int i = 0;i < 10;i++)
		cout << cnt[i] << endl;
}