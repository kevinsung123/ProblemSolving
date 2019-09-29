#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
const int INF = 1e9;
const int MAX_V = 802;
typedef pair<int, int> P;

int main()
{
	int V, E, S1, S2;
	vector<P> adj[MAX_V];

	//정점과 간선
	cin >> V >> E;

	//간선의 정보들
	for (int i = 1; i <= E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(P(v, w));//연결된 정점과, 간선(즉, 거리)
	}

	//반드시 지나야하는 두점
	cin >> S1 >> S2;

	//dist 배열 & 무한대 초기화
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);

	//방문배열
	bool visited[MAX_V] = { 0 };
	memset(visited, 0, sizeof(visited));

	//pq 생성
 	priority_queue<P, vector<P>, greater<P>> pq;

	//시작점 정점 1 dist=0 삽입 
	pq.push(P(0, 1));
	dist[1] = 0;
	

	//모든 정점의 최단 거리 갱신 한정점에서 다른 모든 정점으로 가는 거리 갱신
	while (!pq.empty())
	{
		int cur;
		do
		{
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);//pq가 비어있지 않고  이미 방문한 정점이 아니라면

		if (visited[cur]) break;

		visited[cur] = true;

		for (auto & p : adj[cur])
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
	

	//문제에서 제시한 두 정점을 거치는 경우
	if (dist[S1] != INF && dist[S2] != INF) cout << dist[V] << "\n";
	else puts("-1");


}