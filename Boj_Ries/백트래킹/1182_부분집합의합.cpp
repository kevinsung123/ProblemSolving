#include<iostream>
#include<algorithm>
using namespace std;

int N, S, idx[20];
int cnt, currentSum;


void dfs(int current) //배열에 저장된 현재 인덱스 => 백트래킹 및 조합
{

	if (current == N) return;  //인덱스 초과시

	//현재까지 합이 S이면 cnt++
	if (currentSum + idx[current] == S) cnt++;

	//현재 원소 포함X 하는경우
	dfs(current + 1);

	//현재 원소 포함시 
	currentSum += idx[current];
	dfs(current + 1);

	//백트래킹 마지막원소 더해준것 빼줌

	currentSum -= idx[current];
}

int main()
{
	//ios::sync_with_stdio(false);

	cin >> N >> S;


	for (int i = 0; i < N; i++) cin >> idx[i]; //N개의 정수 입력받음


	dfs(0);

	cout << cnt << endl;


}