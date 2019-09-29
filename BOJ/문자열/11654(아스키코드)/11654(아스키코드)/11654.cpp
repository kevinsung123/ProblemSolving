#include<iostream>
#include<vector>
#include<string>
using namespace std;

char N;

int main(void)
{
	scanf("%c", &N);

	if ('a' >= N && 'z' <= N)
		printf("%d", N - 'a');
	else if ('A' >= N && 'Z' <= N)
		printf("%d", N - 'A');
	else if ('0' >=N && '9' >= N)
		printf("%d", N - '0');
}