//char�迭 ����ؼ� Ǯ���
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
		if (order[index] == -1) order[index] = i;  //�ٽ� ������ �ܾ��� ù ��ġ���� �ִ´�! cnt�� �ϵ� order�� �� ó�� -1�϶��� �����Ѵ�
		
		

	}

	for (int i = 0;i < 26;i++) printf("%d ", order[i]);
}