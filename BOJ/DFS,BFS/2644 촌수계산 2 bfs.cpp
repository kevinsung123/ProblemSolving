#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include<functional>	
using namespace std;
int main()
{
	int n, a, b, m;
	vector<vector<int>> adj;
	scanf("%d ", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	adj.resize(n + 1);
	for (int i = 0;i < m;i++)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	vector<int> dist(n+1, 987654321);
	queue<int> q;
	q.push(a);
	dist[a] = 0;
	int ans = -1;
	while (!q.empty())
	{
		int here = q.front();q.pop();
		for (int i = 0;i < adj[here].size();i++)
		{
			int next = adj[here][i];
			if (dist[next] == 987654321)
			{
				dist[next] = dist[here] + 1;
				if (next == b)  ans=dist[next];
				q.push(next);
			}
		}
	}
	printf("%d\n", ans);
}