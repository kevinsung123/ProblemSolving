#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int DP[1003][1003];
string str;
string tmp;

int palindrome(int low, int high)
{
	if (low > high) return 1; //1글자 예외처리
	int &ret = DP[low][high];
	if (ret != -1) return ret;
	if (str[low] != str[high]) return 0;
	return ret = palindrome(low + 1, high - 1);
}

int main()
{
	cin >> str;
	memset(DP, -1, sizeof(DP));
	palindrome(0, str.size() - 1);
	int len = str.size();
	int a = -1;
	for (int i = 0;i < len;i++)
	{
		if (palindrome(i,len-1))
		{
			a = max(a, len-i);
		}
	}
	printf("%d\n", 2*len-a);
}