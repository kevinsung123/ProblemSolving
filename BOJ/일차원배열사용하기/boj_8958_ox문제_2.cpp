/* c++ string���� �����ذ���*/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	int num = 0;
	int score = 0;
	string str;
	int c; 
	cin >> c;
	while (c--)
	{
		score = 0;
		num = 0;
		cin >> str;
		for (int i = 0;i < str.size();i++)
		{
			if (str[i] == 'x' || str[i] == 'X')
			{
				num = 0;
			}
			else
			{
				num++;
			}
			score += num;
		}
		cout << score << endl;
	}

	
}
