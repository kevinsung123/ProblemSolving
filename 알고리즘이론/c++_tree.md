### 트리
- 그래프의 하위집합 다음조건을 충족
	1. 연결 그래프(컴포넌트가 하나)
	2. 방향을 무시하였을때, 싸이클이 존재하지 않는다
	3.  위의 2개 조건을 충족하면, 트리의 간선의개수는 반드시 트리의 정점개수보다 1작다.
- 트리의 제일 위에 그려진, 가장 상위의 노드를 루트노드(root node)라고 부름
- 루트노드와의 거리를 보통 그 정점의 **깊이(depth)** 또는 **레벨(level)** 라고 부름
- 보통 깊이는 루트가 1또는 0이다
- 트리의 높이는 보통 가장 깊은 정점의 깊이 또는 그에 1을 더한값
- 서로 인접해있는 두 정점이 있을때 깊이 작은쪽은 부모노드(parent node), 큰쪽을 자식노드(child)라고 부름
- 거리가 2이상 차이날떄 조상노드(ancestor) 와 자손노드(descendant)로 부름
- 루트는 제외하면 모든노드가 자기 자신의 부모노드와 이어진 간선을 1개 갖기 떄문에 위의 3번성질이 성립
- 형제자매노드(sibling node) : 같은 부모노드를 둔 서로 다른 자식노드들의 관계
- 리프노드(leaf node) : 자식이 하나도 없는 노드
- 차수(degree) :  자신의 자식수 
- 서브트리(subtree) : 부분 트리 트리에 포함된 또 다른 트리 의미
- 트리가 **재귀적인 성질**을 가짐
- DP나 분할정복 등 기법과 죽이 잘맞음
``` 
ex) 어떤 정점의 서브트리들은 서로 절대 영역이 겹치지 않기 때문에 각 서브트리에 대한 문제를 풀어 합치면 큰 트리의 문제를 풀수 있다(D&Q)
```
```
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class Tree {
public :
	int N; // 정점개수
	vector<int> parent; //부모노드 그 정점의 부모노드번호를 가지고 있음 없으면 -1
	vector<vector<int>> children;//자식 노드 리스트 각 정점마다 갖고있는 리스트 자신의 자식들을 가지고 있음

	//생성자
	Tree() : N(0){}
	Tree(int n) : N(n) {
		parent.resize(N, -1);  //-1로 초기화
		children.resize(N);
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
	{
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
					T.parent[next] = cur;  // next의 부모를 cur로 지정
					T.children[cur].push_back(next);//현재 정점 cur의 자식에 next
				}
			}
		}

		return T;
	}
};

int main()
{
	Graph G(9);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 5);
	G.addEdge(3, 4);
	G.addEdge(4, 5);
	G.addEdge(2, 6);
	G.addEdge(2, 8);
	G.addEdge(6, 7);
	G.addEdge(6, 8);
	G.sortList();
	Tree T = G.makeTree(0);
	T.print();
}
```

- 그래프 순회 방법 : DFS//BFS
- 트리 순회방법 
	- 전위순회(preorder traversal) - 부모-왼-우(DFS 성향)
	- 중위순회(inorder traversal) - 왼-부모-우
	- 후위순회(postorder traversal) - 왼-우-부모
	- 레벨순회(level-order traversal) : 루트를 먼저 방문후, 자식을 큐에넣고, 큐에 있는 노드를 하나씩 방문할때마다 그 자식들을 큐에 넣는다.(BFS성향)
	- 스레드순회(너무 복잡...패스)
	- ![enter image description here](https://blogfiles.pstatic.net/20160815_181/kks227_1471196512852OrYMe_PNG/BinaryTree4.png?type=w3)
- 차수가 2인 트리를 이진트리
- 차수가 K인 트리를 K진트리
