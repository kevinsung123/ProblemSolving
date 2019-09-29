#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
#include<utility>
#include<cstring>
#include<vector>
using namespace std;
const int INF = 1e9;
const int MAX_V = 20002;
typedef pair<int, int> P;
int main()
{
	//ios::sync_with_stdio(false);
	int V, E, K;
	vector<P> adj[MAX_V];//이어진 정점 번호,거리
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(P(v, w));
	}
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	bool visited[MAX_V] = { 0 };
	priority_queue<P, vector<P>, greater<P>> pq;

	//dijkstra
	dist[K] = 0;
	pq.push(P(0, K));
	while (!pq.empty())
	{
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);//cur가 방문한 정점이면 무시
	
		if (visited[cur]) break;//더이상 방문할점이 없으면 종료
		
		visited[cur] = true;
		for (auto &p : adj[cur])
		{
			int next = p.first;
			int d = p.second;
			if (dist[next] > dist[cur] + d)
			{
				dist[next] = dist[cur] + d;
				pq.push(P(dist[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)puts("INF");
		else cout << dist[i] << "\n";
	}

}