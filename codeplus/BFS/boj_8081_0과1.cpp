#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
#define MAX 20000

void bfs(int n)
{
	//n의 나머지수 저장 배열 
	vector<int> visited(n, -1);
	//나머지 수의 부모 및 구성 수 저장배열
	vector<int>parent(n, 0);
	vector<int>pc(n, 0);
	queue<int> q;
	q.push(1);
	visited[1] = 0;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int k = 0; k < 2; k++)
		{
			int next = (cur * 10 + k) % n;
			if (visited[next] == -1)
			{
				visited[next] = visited[cur] + 1;
				parent[next] = cur;
				pc[next] = k;
				q.push(next);
			}

		}
		
	}

	//판단
	if (visited[0] == -1) //못찾음
		cout << "BRAK" << "\n";
	else {
		string ans = "";
		int cur = 0;
		while (cur != 1)//시작수는 1이다
		{
			//ans += (pc[cur]);
			ans += to_string(pc[cur]);
			cur = parent[cur];
		}
		ans += '1';
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}


}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T > 0)
	{
		int N;
		cin >> N;
		// corner case 
		if (N == 1)cout << "1" << "\n";
		else bfs(N);
		T--;
	}

}