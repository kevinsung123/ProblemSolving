#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<istream>
#include<string>
using namespace std;
#define SIZE 1000002
char str[SIZE];



int main(void)
{
	
	int i = 0;
	int word_count = 0;
	
	cin.getline(str, SIZE);
	
	int length = strlen(str);
	cout << "legnth=" << length << endl;
	for (int i = 0; i < length; i++)
		printf("%c", str[i]);
	printf("\n");
	for (int i = 0; i < length; i++)
		printf("%d ", str[i]);

	printf("\nstr[length]=%d", str[length]);
	printf("\nstr[length-1]=%d", str[length - 1]);
	printf("\nstr[length-2]%d", str[length - 2]);
	printf("\nstr[length-3]%d\n", str[length - 3]);
	

	for (i = 0; i < length; i++)
	{
		if (str[i] == ' ')
			word_count++;
	}


	if (str[0] == ' ')
		--word_count;

	if (str[length - 1] == ' ')
		--word_count;

	printf("%d", word_count+1);

	return 0;
}