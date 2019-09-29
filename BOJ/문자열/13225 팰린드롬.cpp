#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
char str[30];
int d[2002][2002];
bool palindrome(char *str)
{
	int cmp = strlen(str) - 1;
	bool flag = true;
	for (int i = 0;i <= strlen(str)/2;i++)
	{
		//printf("size=%d i=%d cmp=%d\n", strlen(str), i, cmp);
		if (str[i] != str[cmp])
		{
			flag = false;
			break;
		}
		cmp--;
	}
	return flag;
}

int dp(int low,int high)
{
	if (low > high) return 1;
	int & ret = d[low][high];
	if (ret != -1) return ret;
	if (str[low] != str[high]) return 0;
	return ret = dp(low + 1, high - 1);

}
int main()
{
	
	scanf("%s", str);
	/*if (palindrome(str))puts("true");
	else puts("false");*/
	int high = strlen(str) - 1;
	if (dp(0, high)) puts("true");
	else puts("false");


}