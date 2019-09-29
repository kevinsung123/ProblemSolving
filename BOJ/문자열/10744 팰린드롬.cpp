#include<string>
#include<vector>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int palindrome(string str)
{
	int len = str.size();
	int last = len - 1;
	bool flag = true;
	for (int i = 0;i <= len / 2;i++)
	{
		if (str[i] != str[last])
		{
			flag = false;
			break;
		}
		last--;
	}
	return flag;
}

int main()
{
	int n;
	string str;
	cin >> n;
	while (n--)
	{
		
		getline(cin, str);
		
		// Keep reading a new line while there is 
		// a blank line 
		while (str.length() == 0) getline(cin, str);
		transform(str.begin(), str.end(), str.begin(), (int(*)(int))tolower);
		if (palindrome(str))puts("Yes");
		else puts("No");
	}
	

}