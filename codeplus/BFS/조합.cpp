#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

int N, M;
int arr[9] = { 1,2,3,4,5};
int chk[9];
int ans[9];

//idx : 채워넣을 idx use : 현재사용하는 인덱스
void dfs(int idx,int use )
{
	if (idx == M)//M=2라면 idx=0,1 채우면 끝 그다음 2가 오면 3번째수 선택이므로 종료
	{
		for (int i = 0; i < M; i++) cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	//순열= 순서를 구분한다
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

	//오른차순정렬
	//sort(arr,arr+N,greater<int>());

	

	dfs(0,0);


}