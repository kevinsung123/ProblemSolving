#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;

class Tree {
public:
	int N;
	vector<int> parent;  //�θ𸮽�Ʈ
	vector<vector<int>> child; //�ڽĳ�帮��Ʈ
	Tree(int n) : N(n)
	{
		parent.resize(N + 2, -1); //-1���ʱ�ȭ
		child.resize(N + 2);
	}

	void set(int a, int b)
	{
		//1�� ������ 1�� �θ��̹Ƿ� �ڽ����� ó��
		if (a == 1 || b == 1)
		{
			if (a == 1)//a=1�ΰ��
			{
				parent[b] = 1;
				child[1].push_back(b);
			}
			else//b=1�ΰ��
			{
				parent[a] = 1;
				child[1].push_back(a);
			}
		}
		else {

			//a�� �θ� �����Ѵٸ�  b�� �ڽ����� ó��
			if (parent[a] != -1) {
				parent[b] = a;//b�Ǻθ� aó��
				child[a].push_back(b); //�ڽ�ó��
				
			}
			//b�� �θ� �����Ѵٸ�  a�� �ڽ����� ó��
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
			//�ش� �θ��忡�� �ڽĳ����ִٸ� ť���ִ´�
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
	cin >> n; //��尳��
	Tree tree(n);  //������
	
	
	for (int i = 0; i < n - 1; i++) //n-1��
	{
		int a, b;
		cin >> a >> b;
		tree.set(a, b);
	}

	//cout << "���=========================\n";
	//for (int i = 1; i <= n; i++)
	//{
	//	cout << i << "�� ����� �θ� =" << tree.parent[i] << "\n";
	//}
	//for (int i = 1; i <= n; i++)
	//{
	//	cout << i<<"�� ����� �ڽ� ����Ʈ :";
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