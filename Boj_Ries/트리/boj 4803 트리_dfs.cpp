#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int N, M;
vector<int> adj[501];
int chk[501];  //트리여부
int ans;
int edge = 0;
int dfs(int idx)
{
	int node = 0;
	chk[idx] = 1;

	for (int i = 0; i < adj[idx].size(); i++)
	{
		int next = adj[idx][i];
		if (chk[next] == 0)
		{
			node+= dfs(next); //노드의수
			
		}
	}

	edge += adj[idx].size();  //간선의 개수 

	return node + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	int cnt = 1;//케이스 번호
	while (1)
	{
		//입력 
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		//초기화 
		ans = 0;
		for (int i = 1; i <= N; i++)
		{
			chk[i] = 0;
			adj[i].clear();
		}


		int a, b;
		//M개 간선을 입력받음 
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		for (int i = 1; i <= N; i++)
		{
			
			int node = 0;
			if (chk[i] == 0) //아직방문하지않았다면
			{
				edge = 0;
				node=dfs(i);
				if (node == (edge / 2) +1)  //노드=간선수+1
				{
					ans++;  //트리개수 증가
				}

			}
		}

		if (ans == 0) cout << "Case " << cnt << ": No trees.\n";
		else if (ans == 1) cout << "Case " << cnt << ": There is one tree.\n";
		else cout << "Case " << cnt << ": A forest of " << ans << " trees.\n";



		cnt++;
	}

}