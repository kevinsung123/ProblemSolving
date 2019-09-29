
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
#define MAX 1000002
int m, n, cnt;
char txt[MAX];
char pat[MAX];
int fail[MAX];
int main()
{
	fgets(txt, sizeof(txt), stdin);
	fgets(pat, sizeof(pat), stdin);
	n = strlen(txt) - 1;
	m = strlen(pat) - 1;
	for (int i = 1, cmp = 0;i < m;i++)
	{
		while (cmp > 0 && pat[i] != pat[cmp]) cmp = fail[cmp - 1];
		if (pat[i] == pat[cmp]) fail[i] = ++cmp;
	}
	vector<int> res;
	for (int i = 0, cmp = 0;i < n;i++)
	{
		while (cmp > 0 && txt[i] != pat[cmp]) cmp = fail[cmp - 1];
		if (txt[i] == pat[cmp])
		{
			if (cmp == m - 1)
			{
				res.push_back(i - cmp + 1);
				cmp = fail[cmp];
			}
			else cmp++;
		}
	}
	cout << res.size() << "\n";
	for (auto i : res)
		cout << i << " ";
}
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 1000003

int fail[MAX];
int n, m, cnt;


int main()
{
	//string pat, txt;
	//getline(cin, txt);
	//getline(cin, pat);
	char pat[MAX];
	char txt[MAX];
	fgets(txt, sizeof(txt), stdin), n = strlen(txt) - 1;
	fgets(pat, sizeof(pat), stdin), m = strlen(pat) - 1;
	for (int i = 1, cmp = 0;i < m;i++)
	{
		while (cmp > 0 && pat[i] != pat[cmp]) cmp = fail[cmp - 1];
		if (pat[i] == pat[cmp]) fail[i] = ++cmp;
	}
	vector<int> result;
	for (int i = 0, cmp = 0;i < n;i++)
	{
		//���� ���ڰ� ����ġ�ϸ� fail���� ��� ����
		while (cmp > 0 && txt[i] != pat[cmp]) cmp = fail[cmp - 1];
		//������ڰ� ��ġ
		if (txt[i] == pat[cmp])
		{
			//pat�� txt[i:i+m-1]���� ã��
			if (cmp==m-1)
			{
				result.push_back(i -cmp+1);
				cmp = fail[cmp];
				
			}
			else cmp++;
		}
	}
	cout <<result.size() << "\n";
	for (auto p : result) printf("%d ", p);
	//1.scanf
	//scanf("%[^\n]s", txt);
	//scanf(" %[^\n]s", pat);
	////3. getline
	//string str, str2;
	//getline(cin, str);
	//strcpy(txt, str.c_str());
	//getline(cin, str);
	//strcpy(pat, str.c_str());int len(char str[])
	/*{
		int i = 0;
		for (i = 0; str[i] != '\0';i++);
		return i;
	}*/



}