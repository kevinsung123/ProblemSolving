#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[26];


int main()
{
	string name;
	int idx = 0;
	bool flag = false;
	cin >> name;
	int len = name.size();
	for (int i = 0;i < len;i++)
	{
		a[name[i] - 'A']++;
	}
	for (int i = 0;i < 26;i++)
	{
		while (a[i])
		{
			if (a[i]== 1)
			{
				//홀수 1개 나오면 못만듬
				if (flag)
				{
					cout << "I'm sorry Hansoo" << "\n";
					return 0;
				}
				flag = true;
				name[len / 2] = i + 'A';
				break;
			}
			//짝수이면 양쪽에 넣고 
			a[i] -= 2;
			name[idx] = name[len - 1 - idx] = i + 'A';
			idx++;
		}
	}
	 cout << name << "\n";
	
}