#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char word[2510];
int isPal[2510][2510];
int minCnt[2510];


int isPalindrome(int l, int r)
{
	if (l >= r)
		return 1;

	int& ret = isPal[l][r];

	if (ret != -1)
		return ret;

	if (word[l] != word[r])
		ret = 0;
	else
		ret = isPalindrome(l + 1, r - 1);

	return ret;
}

int main()
{
	memset(isPal, -1, sizeof(isPal));

	scanf("%s", word + 1);

	int len = strlen(word + 1);

	for (int i = 1; i <= len; i++)
	{
		minCnt[i] = 987654321;
		for (int j = 1; j <= i; j++)
		{
			if (isPalindrome(j, i))
			{
				minCnt[i] = min(minCnt[i], minCnt[j - 1] + 1);
			}
		}
	}

	printf("%d\n", minCnt[len]);

	return 0;
}