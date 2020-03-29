#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;

class Tree {
public:
	int N;
	vector<int> parent;  //부모리스트
	vector<vector<int>> child; //자식노드리스트
	Tree(int n) : N(n)
	{
		parent.resize(N + 2, -1); //-1로초기화
		child.resize(N + 2);
	}

	void set(int a, int b)
	{
		//1이 들어오면 1이 부모이므로 자식으로 처리
		if (a == 1 || b == 1)
		{
			if (a == 1)//a=1인경우
			{
				parent[b] = 1;
				child[1].push_back(b);
			}
			else//b=1인경우
			{
				parent[a] = 1;
				child[1].push_back(a);
			}
		}
		else {

			//a의 부모가 존재한다면  b를 자식으로 처리
			if (parent[a] != -1) {
				parent[b] = a;//b의부모 a처리
				child[a].push_back(b); //자식처리
				
			}
			//b의 부모가 존재한다면  a를 자식으로 처리
			else {
				parent[a] = b;
				child[b].push_back(a);
				
			}
		}
	}

	void ans()
	{
		for (int i = 2; i <= N; i++)
		{
			cout << parent[i] << "\n";
		}
	}

	void levelOrder(int N)
	{
		queue<int> q;
		q.push(N);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			cout << cur << " ";

			int size = child[cur].size();
			int cnt = 0;
			//해당 부모노드에서 자식노드들있다면 큐에넣는다
			while (cnt < size)
			{
				q.push(child[cur][cnt]);
				cnt++;
			}
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n; //노드개수
	Tree tree(n);  //생성자
	
	
	for (int i = 0; i < n - 1; i++) //n-1번
	{
		int a, b;
		cin >> a >> b;
		tree.set(a, b);
	}

	//cout << "결과=========================\n";
	//for (int i = 1; i <= n; i++)
	//{
	//	cout << i << "번 노드의 부모 =" << tree.parent[i] << "\n";
	//}
	//for (int i = 1; i <= n; i++)
	//{
	//	cout << i<<"번 노드의 자식 리스트 :";
	//	for (int m = 0; m < tree.child[i].size(); m++)
	//	{
	//		cout << tree.child[i][m] << " ";
	//	}
	//	cout << "\n";
	//}

	//tree.levelOrder(1);
	//cout << "\n";
	tree.ans();


}