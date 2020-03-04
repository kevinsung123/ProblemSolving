//char배열 사용해서 풀어보기
#include<cstdio>
#include<cstring>
using namespace std;


int main(void)
{
	char s[101];
	int order[26];
	memset(order, -1, 26*sizeof(int));
	scanf("%s", s);
	int index = 0;
	for (int i = 0;i < strlen(s);i++)
	{
		
		index = s[i] - 'a';
		if (order[index] == -1) order[index] = i;  //핵심 나오는 단어의 첫 위치에만 넣는다! cnt는 하되 order에 값 처음 -1일때만 대입한다
		
		

	}

	for (int i = 0;i < 26;i++) printf("%d ", order[i]);
}