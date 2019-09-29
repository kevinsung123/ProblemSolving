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
	cin >> S >> E; //������, ������
	
	//�Ÿ� �迭
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);

	//�湮�迭
	bool visited[MAX_V] = { 0 };
	memset(visited, 0, sizeof(visited));

	//�켱����ť min-heap
	//�ڷ���,����,greater 
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
			//�Ÿ��� ���ŵɰ�� pq�� �ٽ� ����
			if (dist[next] > dist[cur] + d)
			{
				dist[next] = dist[cur] + d;
				pq.push(P(dist[next], next));  //�ٽ� �ּ� ������ �� �Ÿ��� pq�� ����
			}

		}
	}
	cout << dist[E] << "\n";
	
}