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
	//u,v,w ������ �� ����ġ �Է� 
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(P(v, w));

	}
	//�Ÿ� ���ϴ� �ʱ�ȭ 
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	
	//�湮 �迭
	bool visited[MAX_V] = { 0 };
	memset(visited, 0, sizeof(visited));
	//�켱����ť
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push(P(0, K));
	dist[K] = 0;
	while (!pq.empty())
	{
		int cur;
		do
		{
			cur = pq.top().second; pq.pop();

		} while (!pq.empty() && visited[cur]);  //�̹� �湮�� �����̸� ����

		//�� �̻� �湮 �� �� ������ ����
		if (visited[cur]) break;

		//�湮
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