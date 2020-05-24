#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int arr[9];
int chk[9];

void dfs(int idx)
{
	if (idx == M)//M=2라면 idx=0,1 채우면 끝 그다음 2가 오면 3번째수 선택이므로 종료
	{
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	//순열= 순서를 구분한다
	for (int i = 1; i <= N; i++)
	{
		if (!chk[i])//아직 미선택된 수 라면
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