//char �迭�� ���� �ذ� 
//ù��° Ʋ�������� �ʱ�ȭ�� �� test case ���� ���־����
//�ι��� Ǯ���� ���� �迭�� ���� �ֱ⺸�ٴ� �ٷιٷ� ������ֱ�!
#include<cstring>
#include<cstdio>

int main(void)
{
	char s[20];
	char t[300];
	
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(t, 0, sizeof(t));
		int r, k = 0;
		scanf("%d %s",&r,s);
		for (int i = 0;i < strlen(s); i++)
		{
			for (int m = 0;m < r;m++)
			{
				t[k++] = s[i];
			}
		}
		printf("%s\n", t);
	}
}