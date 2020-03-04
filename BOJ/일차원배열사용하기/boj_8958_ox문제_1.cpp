#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main(void)
{
	int c, n;

	scanf("%d", &c);

	while (c--)
	{
		
		string str;
		int i = 0, count = 0, num = 0, sum = 0;
		
		cin >> str;
		for (i = 0;i < str.size();i++)
		{
			if (str[i] == 'x' || str[i] == 'X') num = 0;
			else if (str[i] == 'o' || str[i] == 'O')
			{
				num++;
			}
			sum += num;
		}
		cout << sum << endl;
		

	}


}