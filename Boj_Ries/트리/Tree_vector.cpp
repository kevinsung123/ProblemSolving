#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class Tree {
public:
	int N; // ��������
	vector<int> parent; //�θ���
	vector<vector<int>> children;//�ڽ� ��� ����Ʈ
	vector<int> lc, rc; //�����ڽ�, �������ڽ�

	//������
	Tree() : N(0) {}
	Tree(int n) : N(n) {
		parent.resize(N, -1);  //-1�� �ʱ�ȭ
		lc.resize(N, -1);
		rc.resize(N, -1);

	}

	void setChildren(int p, int l, int r)  //�θ�, ��,�� 
	{
		if (l != -1) parent[l] = p;  //l(�����ڽ�)�� �θ���
		if (r != -1) parent[r] = p;
		lc[p] = l;
		rc[p] = r;
	}

	void preorder(int root) //������ȸ �θ�-��-��
	{
		cout << root << ' ';
		if (lc[root] != -1) preorder(lc[root]); //�����ڽ��ִٸ�
		if (rc[root] != -1) preorder(rc[root]); //������ �ڽ� �ִٸ� 

	}

	void inorder(int root) //������ȸ �� -�θ� -��
	{
		if (lc[root] != -1) inorder(lc[root]);
		cout << root << ' ';
		if (rc[root] != -1) inorder(rc[root]);
	}

	void postorder(int root) // ������ȸ ��-��-�θ�
	{
		if (lc[root] != -1) postorder(lc[root]);
		if (rc[root] != -1) postorder(rc[root]);
		cout << root << " ";
	}

	void levelorder(int root) //������ȸ bfs
	{
		queue<int>q; 
		q.push(root);  //��Ʈ�� ���� �湮�ϰ� �ڽ��� ť���ְ�, ť�� �ִ� ��带 �湮�Ҷ����� �ڽĵ��� �ִ´�
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			cout << cur << " ";  //ť�� �ִ� ������� ����Ѵ�
			if (lc[cur] != -1) q.push(lc[cur]); //���� �ڽ� ������ ť�� �ְ� 
			if (rc[cur] != -1) q.push(rc[cur]); //������ �ڽ� ������ ť���ְ�
		}
	}
	//Ʈ�� ���� ���ϴ� �Լ� ����Ʈ������ ��� �˾ƾ� �ڽ��� �䵵 ���� �� �����Ƿ� ������ȸ�� �����
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
	int N;//������ ����
	vector<vector<int>> adj; //��������Ʈ

	Graph() : N(0) {}
	Graph(int n) : N(n) { adj.resize(N); }

	//�����߰��Լ�
	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//��� ����Ʈ�������� ���� ��ȣ ����
	void sortList()
	{j
		for (int i = 0; i < N; i++) sort(adj[i].begin(), adj[i].end());
	}

	Tree makeTree(int root)
	{
		Tree T(N);
		vector<bool> chk(N, false);//�湮��������
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