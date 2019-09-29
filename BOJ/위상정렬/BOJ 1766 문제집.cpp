#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
#define MAX 32001
#define pq priority_queue
int N, M;
int indegree[MAX];  //indegree 배열
vector<vector<int>> adj;  //인접벡터
vector<int> store;  //결과 담을 벡터

int main()
{
	cin >> N >> M;
	adj.resize(N + 1);
	for (int i = 1;i <= M;i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++; //indegree 배열
	}

	//위상정렬 시작
	pq <int, vector<int>, greater<int>> minheap;
	//queue<int> minheap;

	for (int i = 1; i<= N;i++)
	{
		if (indegree[i] == 0)
		{
			minheap.push(i);
		}
	}

	while (!minheap.empty())
	{
		int now = minheap.top();
		minheap.pop();
		store.push_back(now);
		
		
		//iterate through all its adjacency nodes
		//of dequeued node u and decrease their indegree by 1
		for (int i = 0; i < adj[now].size() ; i++)
		{
		
			int next = adj[now][i];
			if (--indegree[next] == 0)
			{
				
				minheap.push(next);
			}
		}

	}

	for (int i = 0;i < store.size();i++)
		cout << store[i] << " ";
	cout << "\n";


}
