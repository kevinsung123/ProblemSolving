#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

int N, M;
int arr[9] = { 1,2,3,4,5};
int chk[9];
int ans[9];

//idx : ä������ idx use : �������ϴ� �ε���
void dfs(int idx,int use )
{
	if (idx == M)//M=2��� idx=0,1 ä��� �� �״��� 2�� ���� 3��°�� �����̹Ƿ� ����
	{
		for (int i = 0; i < M; i++) cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	//����= ������ �����Ѵ�
	for (int i = use; i < 5; i++)
	{
		if (!chk[i])
		{
			chk[i] = 1;
			ans[idx] = arr[i];
			dfs(idx+1, i);
			chk[i] = 0;
		}

	}
}


int main()
{
	ios::sync_with_stdio(false);

	cin >> M;
	//cin >> N >> M;
	//for (int i = 0; i < N; i++)cin >> arr[i];

	//������������
	//sort(arr,arr+N,greater<int>());

	

	dfs(0,0);


}