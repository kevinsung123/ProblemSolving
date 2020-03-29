#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

class Tree {
public :
	int N; //��� ����
	vector<char> parent;
	vector<char> left;
	vector<char> right;


	//������
	Tree(int n) :N(n)
	{
		parent.resize(N, -1);
		left.resize(N, -1);
		right.resize(N, -1);
	}

	void set(char p, char l, char r) //��,��,��
	{
		//�ڽõ��� �θ� ����

		if (l != '.') parent[l-'A'] = p-'A';
		if (r != '.') parent[r-'A'] = p-'A';
		//�ڽļ���
		if(l!='.')
			left[p-'A'] = l-'A';
		if(r!='.')
			right[p-'A'] = r-'A';
	}

	//������ȸ
	void preOrder(char root)
	{
		//char +char �ϸ� �ڵ����� integer�� type casting �Ǵµ�?
		cout << static_cast<char>(root +'A');
		if (left[root] != -1) preOrder(left[root]);
		if (right[root] != -1) preOrder(right[root]);
	}

	//������ȸ
	void inOrder(char root)
	{
		
		if (left[root] != -1) inOrder(left[root]);
		cout << static_cast<char>(root + 'A');
		if (right[root] != -1) inOrder(right[root]);
	}

	//������ȸ
	void postOrder(char root)
	{

		if (left[root] != -1) postOrder(left[root]);
		if (right[root] != -1) postOrder(right[root]);
		cout << static_cast<char>(root + 'A');
	}

};


int main()
{
	ios::sync_with_stdio(false);
	int N = 0;
	cin >> N;
	Tree T(N);  //N���� ��带 ���� Ʈ�� ����
	for (int i = 0; i < N; i++)
	{
		char p, l, r;
		cin >> p >> l >> r;
		T.set(p, l, r);
	}

	T.preOrder(0);
	cout << "\n";
	T.inOrder(0);
	cout << "\n";
	T.postOrder(0);
	cout << "\n";
}