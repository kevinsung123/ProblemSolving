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

	//������ ����
	cin >> V >> E;

	//������ ������
	for (int i = 1; i <= E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(P(v, w));//����� ������, ����(��, �Ÿ�)
	}

	//�ݵ�� �������ϴ� ����
	cin >> S1 >> S2;

	//dist �迭 & ���Ѵ� �ʱ�ȭ
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);

	//�湮�迭
	bool visited[MAX_V] = { 0 };
	memset(visited, 0, sizeof(visited));

	//pq ����
 	priority_queue<P, vector<P>, greater<P>> pq;

	//������ ���� 1 dist=0 ���� 
	pq.push(P(0, 1));
	dist[1] = 0;
	

	//��� ������ �ִ� �Ÿ� ���� ���������� �ٸ� ��� �������� ���� �Ÿ� ����
	while (!pq.empty())
	{
		int cur;
		do
		{
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);//pq�� ������� �ʰ�  �̹� �湮�� ������ �ƴ϶��

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
	

	//�������� ������ �� ������ ��ġ�� ���
	if (dist[S1] != INF && dist[S2] != INF) cout << dist[V] << "\n";
	else puts("-1");


}