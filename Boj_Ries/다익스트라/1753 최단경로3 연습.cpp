#include<iostream>
#include<queue>	
#include<utility>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 1e9;
const int MAX_V = 20001;
typedef pair<int, int> P;

int main()
{
	int V, E, K;
	vector<P>adj[MAX_V];
	cin >> V >> E >> K;
	//u,v,w 정점과 그 가중치 입력 
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(P(v, w));

	}
	//거리 무하댄 초기화 
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	
	//방문 배열
	bool visited[MAX_V] = { 0 };
	memset(visited, 0, sizeof(visited));
	//우선순위큐
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push(P(0, K));
	dist[K] = 0;
	while (!pq.empty())
	{
		int cur;
		do
		{
			cur = pq.top().second; pq.pop();

		} while (!pq.empty() && visited[cur]);  //이미 방문한 정점이면 무시

		//더 이상 방문 할 수 없으면 종료
		if (visited[cur]) break;

		//방문
		visited[cur] = true;

		
		for (auto & p : adj[cur])
		{
			int next = p.first;
			int d = p.second;
			cout << next << "," << d << "\n";
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