#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 100002*2
char str[MAX];
char  tmp[MAX];
int A[MAX];
void manachers(char str[],int N)
{
	//p는 중심 r=p+A[p]
	int r = 0, p = 0;
	for (int i = 0;i < N;i++)
	{
		//i<=r이면 i가 팰린드롬에 포함
		if (i <= r) A[i] = min(r - i, A[2 * p - i]);
		else A[i] = 0;
		//같으면 계속 증가
		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && str[i - A[i] - 1] == str[ i + A[i] + 1]) 
			A[i]++;
		//더 긴 팰린드롬 만났으면 중심과 r를 갱신
		if (r < i + A[i])
		{
			r = i + A[i];
			p = i;
		}
	}
}
int main()
{
	
	scanf("%s", tmp);
	for (int i = 0;i < strlen(tmp);i++)
	{
		strncat(str, "#",1);
		strncat(str, &tmp[i],1);
	}
	strncat(str, "#",1);
	manachers(str, strlen(str));
	int ans = -1;
	for (int i = 0;i < strlen(str);i++)
	{
		ans = max(ans, A[i]);
	}
	printf("%d\n", ans);

}