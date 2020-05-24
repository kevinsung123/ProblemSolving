#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int arr[9];
int chk[9];

void dfs(int idx)
{
	if (idx == M)//M=2��� idx=0,1 ä��� �� �״��� 2�� ���� 3��°�� �����̹Ƿ� ����
	{
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	//����= ������ �����Ѵ�
	for (int i = 1; i <= N; i++)
	{
		if (!chk[i])//���� �̼��õ� �� ���
		{
			chk[i] = 1;
			arr[idx] = i;
			dfs(idx + 1);
			chk[i] = 0;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M;
	
	dfs(0);

	
}