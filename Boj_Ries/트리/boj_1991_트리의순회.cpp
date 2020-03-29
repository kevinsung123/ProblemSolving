#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

class Tree {
public :
	int N; //노드 개수
	vector<char> parent;
	vector<char> left;
	vector<char> right;


	//생성자
	Tree(int n) :N(n)
	{
		parent.resize(N, -1);
		left.resize(N, -1);
		right.resize(N, -1);
	}

	void set(char p, char l, char r) //부,왼,오
	{
		//자시들의 부모 설정

		if (l != '.') parent[l-'A'] = p-'A';
		if (r != '.') parent[r-'A'] = p-'A';
		//자식설정
		if(l!='.')
			left[p-'A'] = l-'A';
		if(r!='.')
			right[p-'A'] = r-'A';
	}

	//전위순회
	void preOrder(char root)
	{
		//char +char 하면 자동으로 integer로 type casting 되는듯?
		cout << static_cast<char>(root +'A');
		if (left[root] != -1) preOrder(left[root]);
		if (right[root] != -1) preOrder(right[root]);
	}

	//중위순회
	void inOrder(char root)
	{
		
		if (left[root] != -1) inOrder(left[root]);
		cout << static_cast<char>(root + 'A');
		if (right[root] != -1) inOrder(right[root]);
	}

	//후위순회
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
	Tree T(N);  //N개를 노드를 갖는 트리 생성
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