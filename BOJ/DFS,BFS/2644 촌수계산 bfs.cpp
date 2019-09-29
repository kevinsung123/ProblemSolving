#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>	
#include<utility>
using namespace std;
const int MAX_V= 101;
const int INF = 1000000;
int n, m;
int a, b;
vector<vector<int>>adj;
int bfs(int a, int b)
{
	queue<int> q;
	vector<int> dist(n + 1, 987654321);
	dist[a] = 0;
	q.push(a);
	while (!q.empty())
	{
		int here = q.front();q.pop();
		for (int i = 0;i < adj[here].size();i++)
		{
			int next = adj[here][i];
			if (dist[next] == 987654321)
			{
				dist[next] = dist[here] + 1;
				if (next == b) return dist[next];
				q.push(next);
			}
		}
	}
	return -1;
}

int main()
{
	
	scanf(" %d", &n);
	scanf(" %d %d", &a, &b);
	scanf(" %d ", &m);
	
	adj.resize(n+1);
	for (int i = 0;i < m;i++)
	{
		int p = 0, q = 0;
		scanf("%d %d", &p,&q);
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	printf("%d", bfs(a, b));


}

