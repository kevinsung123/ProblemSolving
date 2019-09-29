#include<stdio.h>
char str[101];

int strlen(char str[])
{
	int size = 0;
	for (size = 0;str[size] != '\0';size++);
	return size;
}
int palindrome(int low, int high)
{
	if (low > high) return 1;
	
	if (str[low] != str[high]) return 0;

	int ret = palindrome(low + 1, high - 1);

	return ret;
}

int check(char str[])
{
	int flag = 1;
	int j = strlen(str) - 1;
	int size = (strlen(str) - 1) / 2;
	for (int i = 0;i<=size;i++)
	{
		if (str[i] != str[j]) flag = 0;
		j--;
	}
	return flag;
}

int main()
{
	scanf("%s", str);
	
	//size는 문자열의 개수리으몰 index를 넣으려면 -1!!
	/*if (palindrome(0, strlen(str)-1)) printf("1\n");
	else printf("0\n");*/
	
	
	if (check(str)) printf("1\n");
	else printf("0\n");

}