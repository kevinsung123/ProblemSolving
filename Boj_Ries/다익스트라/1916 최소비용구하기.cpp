#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<cstring>
#include<vector>
using namespace std;
const int MAX_V = 100002;
const int INF = 1e9;
typedef pair<int, int> P;

int main()
{
	int N,M,S,E;
	cin >> N >> M;
	vector<P> adj[MAX_V];
	for (int i = 1; i <= M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(P(v, w));
			
	}
	cin >> S >> E; //시작점, 도착점
	
	//거리 배열
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);

	//방문배열
	bool visited[MAX_V] = { 0 };
	memset(visited, 0, sizeof(visited));

	//우선순위큐 min-heap
	//자료형,벡터,greater 
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push(P(0, S));
	dist[S] = 0;

	while (!pq.empty())
	{
		int cur;
		do
		{
			cur = pq.top().second; pq.pop();
		} while (!pq.empty() && visited[cur]);

		if (visited[cur]) break;

		visited[cur] = true;

		for (auto &p : adj[cur])
		{
			int next = p.first;
			int d = p.second;
			//거리가 갱신될경우 pq에 다시 넣음
			if (dist[next] > dist[cur] + d)
			{
				dist[next] = dist[cur] + d;
				pq.push(P(dist[next], next));  //다시 최소 정점와 그 거리를 pq에 넣음
			}

		}
	}
	cout << dist[E] << "\n";
	
}