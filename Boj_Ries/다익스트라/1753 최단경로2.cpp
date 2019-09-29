#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
#include<cstring>
#include<vector>
using namespace std;
const int INF = 1e9;
const int MAX_V = 20002;
typedef pair<int, int> P;
int main()
{
	int V, E, K;//정점,간선,시작점
	vector<P> adj[MAX_V];
	cin >> V >> E >> K;
	//간선 입력 
	for (int i = 0; i < E;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(P(v, w));  //거리, vertex
	}
	//거리 배열
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	//방문 배열
	bool visited[MAX_V] = { 0 };
	memset(visited, 0, sizeof(visited));
	//최소 우선순위 큐
	priority_queue<P, vector<P> ,greater<P>> pq;
	pq.push(P(0, K)); //최초 거리0, 시작점 K
	dist[K] = 0;
	while (!pq.empty())  //O(ElogV)
	{
		int cur;
		do
		{
			cur = pq.top().second; pq.pop();
		} while (!pq.empty() && visited[cur]);

		if (visited[cur]) break;
		//방문 표시
		visited[cur] = true;

		for (auto &p : adj[cur])
		{
			int next = p.first;
			int d = p.second;
			//해당정점에서 인접하고 아직 방문하지 점 갱신
			if (dist[next] > dist[cur] + d) 
			{
				dist[next] = dist[cur] + d;
				pq.push(P(dist[next], next));
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF) puts("INF");
		else cout << dist[i] << "\n";
	}


}