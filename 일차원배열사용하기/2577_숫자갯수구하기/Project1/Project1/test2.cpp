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
	
	
	
	
	//숫자 길이만큼 동적할당
	do {
		sum = sum / 10;
		len++;
	} while (sum < 0);

	
	char * str = new char[len];

	//숫자를 문자열로 변환
	itoa(sum, str, 10);

	for (int i = 0;i < strlen(str);i++)
	{
		cnt[str[i]]++;
		
	}

	for (int i = 0;i < 10;i++)
		cout << cnt[i] << endl;
}