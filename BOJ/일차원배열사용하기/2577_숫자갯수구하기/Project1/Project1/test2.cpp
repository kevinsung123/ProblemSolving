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

	//숫자 길이만큼 동적할당
	do {
		sum = sum / 10;
		len++;
	} while (sum > 0);

	char * str = new char[len+1];
	//숫자를 문자열로 변환
	sprintf(str, "%d", temp);
	str[strlen(str)] = 0;  

	


	for (int i = 0; i < strlen(str);i++)
	{
		cnt[str[i]-'0']++;   //index에 넣을때 조심하기!!! str[i]는 char이므로 숫자로 바꿔주어야한다.
	}

	for (int i = 0;i < 10;i++)
	{
		printf("%d\n", cnt[i]);
	}
}