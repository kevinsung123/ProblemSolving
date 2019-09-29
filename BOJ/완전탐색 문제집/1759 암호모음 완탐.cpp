#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char alpha[17];
char match[17];
bool check[17];
int L, C;

//그냥 조합이 아니라 한번씩만!!
void dfs(int idx,int prev)
{
	if (idx == L)
	{
		int m = 0, n = 0;
		for (int i = 0;i < L;i++)
		{
			if (match[i] == 'a' ||
				match[i] == 'e' ||
				match[i] == 'i' ||
				match[i] == 'o' ||
				match[i] == 'u')
				m++;
			else n++;

		}
		
		if (m >= 1 && n>= 2)
		{
			
				printf("%s", match);
			printf("\n");
		}
		return;
	}

	for (int i = prev;i < C;i++)
	{
		if (!check[i])
		{
			check[i] = true;
			match[idx] = alpha[i];
			dfs(idx + 1,i+1);
			check[i] = false;
		}
	}
	return;
}


int main()
{

	
	scanf("%d %d", &L, &C);
	for (int i = 0;i < C;i++)
	{
		scanf(" %c", &alpha[i]);
	}
	//sort가 ㅂㅓㅁ위를 넘어섯 이상하게됨 
	sort(alpha, alpha+C);
	dfs(0,0);
	
}
