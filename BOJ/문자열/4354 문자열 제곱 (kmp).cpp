#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX 1000004
int main()
{
	while (true)
	{
		char txt[MAX];
		scanf("%s", txt);
		if (txt[0] == '.') break;
		int len = strlen(txt);
		int fail[MAX] = { 0 };
		for (int i = 1, cmp = 0;i < len;i++)
		{
			while (cmp > 0 && txt[i] != txt[cmp]) cmp = fail[cmp - 1];
			if (txt[i] == txt[cmp]) fail[i] = ++cmp;
		}
		int q = fail[len - 1];
		int r = len - q;
		if (q == 0 || q % r != 0) puts("1");
		else printf("%d\n", q / r + 1);
	}
}