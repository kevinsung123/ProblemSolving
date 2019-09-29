#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<tuple>
#include<set>
#include<queue>
using namespace std;
int check[201][201][201];
int main()
{
	ios::sync_with_stdio(false);
	int max_a[3] = { 0 };	
	cin >> max_a[0] >> max_a[1] >> max_a[2];  //물의 최대용량
	int arr[3] = { 0,0,max_a[2] };// 현재 상태
	set<int> res;//결과 
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,max_a[2] });
	check[0][0][max_a[2]];
	while (!q.empty())
	{
		int a, b, c;
		tie(a, b, c) = q.front(); q.pop();
		arr[0] = a; arr[1] = b; arr[2] = c;//현재 상태 갱신
		check[a][b][c] = 1;  //방문처리
		//printf("a=%d b=%d c=%d\n", a, b, c);
		if (a == 0) res.insert(c);  //A=0일때 C물의양 담기
		for (int i = 0; i < 3; i++) //물을 담을수 있는 통 찾기
		{
			if (arr[i] < max_a[i])//물을 넣을수 있다면
			{
				for (int j = 0; j < 3; j++)//물이 있는 통에서 옮기기
				{
					int next[3] = { arr[0],arr[1],arr[2] };  //다음상태
					if (i == j || arr[j] == 0) continue;
					int diff = min(arr[j],abs(max_a[i]-arr[i])); // 넣으려는 물통의 max-현재 or 물이있는곳의 최대 중 작은것
					next[i] += diff;
					next[j] -= diff;
					if (check[next[0]][next[1]][next[2]]) continue;
					q.push({ next[0],next[1],next[2] });
					//printf("다음 %d %d %d\n", next[0], next[1], next[2]);
				
				}
			}
		}
	}
	
	for (auto x : res)cout << x << " ";
	cout << "\n";

}