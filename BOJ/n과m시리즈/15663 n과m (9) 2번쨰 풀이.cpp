#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int check[11];
int num[11];
int match[11];
int n, m;
void perm(int idx)
{
	if (idx == m)
	{
		for (int i = 0;i < m;i++)cout << match[i] << " ";
		cout << "\n";
		return;
	}
	int prev = 0;
	for (int i = 0;i < n;i++)
	{
		if (check[num[i]] && num[i]!=prev)
		{
			check[num[i]]--;
			match[idx] = num[i];
			perm(idx + 1);
			prev = num[i];  //match���� ù���� ���� ���� �ι��� ���ں��� ���� ���ڸ� �ǹ�! ���� ���� ������ ����
			check[num[i]]++;
		}
		
	}
}
int main()
{
	cin >> n >> m;
	int tmp = 0;
	for (int i = 0;i < n;i++)
	{
		cin >> tmp;
		num[i] = tmp;
		check[tmp]++;
	}
	sort(num, num + n);
	perm(0);
	return 0;
}