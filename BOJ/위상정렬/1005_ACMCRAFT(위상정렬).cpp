#include<queue>
#include<iostream>
#include<vector>
using namespace std;
int T, N, K, w;
vector<int> time; //�ǹ� ���µ� �ɸ��½ð�
vector<int> dist;
vector<int> indegree; //indegree ���� �迭
vector<int> store;//���� ���� �迭
vector <vector<int>> map;  //graph


queue<int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;


	while (T--)
	{
		time.clear();
		indegree.clear();
		store.clear();
		map.clear();
		dist.clear();
		cin >> N >> K;

		indegree.resize(N + 1);
		time.resize(N + 1);
		//store.resize(N + 1);
		map.resize(N + 1);
		dist.resize(N + 1);
		//�� �ǹ� �ð� 
		for (int i = 1;i <= N;i++)
			cin >> time[i];

		//���� �Է�
		for (int i = 0;i < K;i++)
		{
			//u: source, v: destination
			int u, v;
			cin >> u >> v;
			map[u].push_back(v);
			indegree[v]++; //indegree count


		}
		//������ �����ǹ�
		cin >> w;

		queue<int> q;

		//�������Ľ���
		for (int i = 1;i <= N;i++)
		{
			//enqueu all vertices with indegree 0
			if (indegree[i] == 0)
			{
				q.push(i);
				dist[i] = time[i];
			}
		}
		//count of visited nodes
		int cnt = 0;
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			store.push_back(now);

			//iterator adjacency nodes[i]

			for (int i = 0;i < map[now].size();i++)
			{
				int next = map[now][i];//���� vertex�� ������ vertices
				if (--indegree[next] == 0)
				{
					q.push(next);
				}
				//�ð� ���� 
				if (dist[next] < dist[now] + time[next])
					dist[next] = dist[now] + time[next];
			}
			
			cnt++;
		}

		cout << dist[w] << "\n";

		for (int i = 0;i < store.size();i++)
			cout << store[i] << " ";
		cout << "\n";
	}
}
