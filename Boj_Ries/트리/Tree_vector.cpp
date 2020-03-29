#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class Tree {
public:
	int N; // 정점개수
	vector<int> parent; //부모노드
	vector<vector<int>> children;//자식 노드 리스트
	vector<int> lc, rc; //왼쪽자식, 오른쪽자식

	//생성자
	Tree() : N(0) {}
	Tree(int n) : N(n) {
		parent.resize(N, -1);  //-1로 초기화
		lc.resize(N, -1);
		rc.resize(N, -1);

	}

	void setChildren(int p, int l, int r)  //부모, 왼,오 
	{
		if (l != -1) parent[l] = p;  //l(왼쪽자식)의 부모설정
		if (r != -1) parent[r] = p;
		lc[p] = l;
		rc[p] = r;
	}

	void preorder(int root) //전위순회 부모-왼-오
	{
		cout << root << ' ';
		if (lc[root] != -1) preorder(lc[root]); //왼쪽자식있다면
		if (rc[root] != -1) preorder(rc[root]); //오른쪽 자식 있다면 

	}

	void inorder(int root) //중위순회 왼 -부모 -우
	{
		if (lc[root] != -1) inorder(lc[root]);
		cout << root << ' ';
		if (rc[root] != -1) inorder(rc[root]);
	}

	void postorder(int root) // 후위순회 왼-우-부모
	{
		if (lc[root] != -1) postorder(lc[root]);
		if (rc[root] != -1) postorder(rc[root]);
		cout << root << " ";
	}

	void levelorder(int root) //레베순회 bfs
	{
		queue<int>q; 
		q.push(root);  //루트를 먼저 방문하고 자식을 큐에넣고, 큐에 있는 노드를 방문할때마다 자식들을 넣는다
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			cout << cur << " ";  //큐에 넣는 순서대로 출력한다
			if (lc[cur] != -1) q.push(lc[cur]); //왼쪽 자식 있으면 큐에 넣고 
			if (rc[cur] != -1) q.push(rc[cur]); //오른쪽 자식 있으면 큐에넣고
		}
	}
	//트리 높이 구하는 함수 서브트리들을 모두 알아야 자신의 답도 구할 수 있으므로 후위순회에 가까움
	int getHeight(int root)
	{
		int result = 1;
		for (int c : children[root])
		{
			result = max(result, getHeight(c) + 1);
		}
		return result;
	}

	void print() {
		for (int i = 0; i < N; i++)
		{
			cout << "Node " << i << ": parent(";
			if (parent[i] != -1) cout << parent[i];
			else cout << "-";
			cout << "), childern(";
			for (int j = 0; j < children[i].size(); j++)
			{
				cout << children[i][j];
				if (j < children[i].size() - 1)cout << ", ";

			}
			cout << ")" << "\n";

		}

	}
};
class Graph {
public:
	int N;//정점의 개수
	vector<vector<int>> adj; //인접리스트

	Graph() : N(0) {}
	Graph(int n) : N(n) { adj.resize(N); }

	//간선추가함수
	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//모든 리스트의인접한 정점 번호 정렬
	void sortList()
	{j
		for (int i = 0; i < N; i++) sort(adj[i].begin(), adj[i].end());
	}

	Tree makeTree(int root)
	{
		Tree T(N);
		vector<bool> chk(N, false);//방문여부저장
		queue<int> Q;

		chk[root] = true;
		Q.push(root);
		while (!Q.empty())
		{
			int cur = Q.front();
			Q.pop();
			for (int next : adj[cur])
			{
				if (!chk[next])
				{
					chk[next] = true;
					Q.push(next);
					T.parent[next] = cur;
					T.children[cur].push_back(next);
				}
			}
		}

		return T;
	}
};

int main()
{
	//Graph G(9);
	//G.addEdge(0, 1);
	//G.addEdge(0, 2);
	//G.addEdge(1, 3);
	//G.addEdge(1, 5);
	//G.addEdge(3, 4);
	//G.addEdge(4, 5);
	//G.addEdge(2, 6);
	//G.addEdge(2, 8);
	//G.addEdge(6, 7);
	//G.addEdge(6, 8);
	//G.sortList();
	//Tree T = G.makeTree(0);

	//T.print();
	Tree T(10);
	T.setChildren(0, 1, 2);
	T.setChildren(1, 3, 4);
	T.setChildren(2, -1, 5);
	T.setChildren(3, 6, 7);
	T.setChildren(5, 8, 9);


	cout << "Preorder : ";
	T.preorder(0);
	cout << "\n";
	cout << "Inorder : ";
	T.inorder(0);
	cout << "\n";
	cout << "postorder : ";
	T.postorder(0);
	cout << "\n";
	cout << "levelorder : ";
	T.levelorder(0);
	cout << "\n";
}