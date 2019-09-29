#include<vector>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char str[103];
int main()
{
	scanf("%s", str);
	int flag = 1;
	int j = strlen(str) - 1;
	for (int i = 0;i <= strlen(str)/2;i++)
	{
		if (str[i] != str[j]) flag = 0;
		j--;
	}
	printf("%d\n", flag);
}