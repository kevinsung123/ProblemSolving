#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, K;
int check[11];
int num[11];
int var[11];
int match[11];
int cnt;
void perm(int idx)
{
	if (idx == M)
	{
		for (int i = 0;i < M;i++)cout << match[i] << " ";
		cout << "\n";
		cnt++;
		return;
	}
	for (int i = 1;i <= N;i++)
	{
		if (!check[i])
		{
			check[i] = true;
			match[idx] = i;
			perm(idx + 1);
			check[i] = false;
		}
	}
}

void comb(int idx, int use)
{
	if (idx == M)
	{
		for (int i = 0;i < M;i++)cout << match[i] << " ";
		cout << "\n";
			cnt++;
		return;
	}
	for (int i = use;i <= N;i++)
	{
		if (!check[i])
		{
			check[i] = true;
			match[idx] = i;
			comb(idx + 1, i + 1);
			check[i] = false;
		}
	}
}

void multiperm(int idx)
{
	if (idx == M)
	{
		for (int i = 0;i < M;i++)cout << var[match[i]] << " ";
		cout << "\n";
		cnt++;
		return;
	}

	for (int i = 0;i < N;i++)
	{
		if (check[var[i]]>0)
		{

			check[var[i]]--;
			match[idx] = i;
			multiperm(idx + 1);
			check[var[i]]++;
		}
		
		
	}
}

int main()
{
	cin >> N >> M;
	/*perm(0);
	printf("cnt=%d\n", cnt);
	cnt = 0;
	puts("end");
	comb(0, 1);
	printf("cnt=%d\n", cnt);
	cnt = 0;
	puts("end");*/
	for (int i = 0;i < N;i++)
	{
		int tmp = 0;
		cin >> tmp;
		num[i] = tmp;
		check[tmp]++;
		
	}
	int k = 0;
	sort(num, num + N);
	for (int i = 0;i < N;i++)
	{
		if (num[i] != num[i + 1]) var[k++] = num[i];
	}
	
	multiperm(0);
	
	return 0;
}