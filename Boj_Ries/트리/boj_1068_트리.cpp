#include<iostream>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
int M;
int parent[51];
vector<int> child[51];
int chk[51];
int ans;


void bfs(int node)
{
	queue<int>q;
	q.push(node);
	chk[node] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		//자식노드가 있는경우 그리고 leaf node를 지우는 경우
		if (child[cur].size() == 0 || (child[cur].size() == 1 && child[cur][0]==M))
		{
			ans++;
		}
		else {

			for (int i = 0; i < child[cur].size(); i++)
			{
				int next = child[cur][i];
				if (chk[next] == 0)
				{
					if (parent[next] != -2) //지워진 노드가 아니라면
						q.push(next);

				}
				
			}
		}
		



	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N;  //노드수
	int root = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> parent[i]; //부모노드 지정
		if (parent[i] != -1) //루트가 아니라면
			child[parent[i]].push_back(i); //자식노드 저장
		else if (parent[i] == -1)
			root = i;
	}
	cin >> M; //지울노드

	//지우는과정
	parent[M] = -2;
	//자식노드 지우는과정
	for (int i = 0; i < N; i++)
	{
		if (parent[i] == M) parent[i] = -2;
	}

	//루트노드를 찾아서 넣음
	if (root == M) cout << 0 << "\n";
	else {
		bfs(root);
		cout << ans << "\n";
	}

