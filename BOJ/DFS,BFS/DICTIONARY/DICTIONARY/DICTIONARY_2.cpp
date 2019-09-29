#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

vector< vector<int> > adj; //�������
vector<int> visited; //�湮����
vector<int> order;//���� ���
vector<string> words;//�Է¹��� ���ڿ���
void dfs(int here);
void makegraph();
vector<int> topologysort();


int main(void)
{

	ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		words.clear();//���ڿ� �Է¹ޱ��� �ʱ�ȭ
		order.clear();
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			words.push_back(str); 

		}
	
		makegraph(); //�׷��� �𵨸��ϱ�
		
		vector<int> ans = topologysort(); //���� ���
	
		if (ans.empty()) {
			cout << "INVALD HYPOTHESIS";
		
		}
		else
		{
			for (int i = 0; i < ans.size(); i++)
				cout << char(ans[i] + 'a');
		}
		printf("\n");
	}
	
	return 0;
}

void makegraph()
{
	adj.clear(); //���ο� ������ĸ���� �ʱ�ȭ
	adj = vector< vector<int> >(26, vector<int>(26, 0)); //���ĺ�ũ���� 26*26 �������迭 ����

	for (int j = 1; j < words.size(); j++)  //�Ǽ��Ѻκ�!!!!! n�� �ƴ϶� wordsũ�⸸ŭ ���ƾ���
	{
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());
	
		for (int k = 0; k < len; k++) 
		{
			if (words[i][k] != words[j][k])  //i�� �տ�, j�� �ڿ� ���ڿ�
			{
				int a = words[j][k] - 'a';
				int b = words[i][k] - 'a';
				adj[a][b] = 1; //adj[i][j]=1�̸� i�� j���� �տ� �;��Ѵ�
				break; //�̰� ������ words[i][k]�� �ٸ��κ��� ���ϹǷ� vector subscript range error
			}
		}
	}
}

void  dfs(int here)
{

	visited[here] = 1;//here�� ������ �湮
	
	for (int there = 0; there < adj.size(); ++there)  //vertex����ŭ for�� 
	{
		if (visited[there] == 0 && adj[here][there]==1) //�ٸ� ��������� Ȯ���ϴµ� �湮�����ʰ� ������ �ִ� ����� ������ �湮
			dfs(there);
	}
	order.push_back(here);//dfs�� ����Ǵ� ������� ���� ����  
	//�� �κп��� �Ǽ�!!!!!!!!there�� �ƴ϶� here�� �־����..
}
//adj��������� ������ topologysort�� �Ѵ�
vector<int> topologysort()
{
	int n = adj.size();
	visited = vector<int>(n, 0);
	order.clear();//���ο� �׽�Ʈ���̽��� order�� �ʱ�ȭ
	
	//��������� ��ȯ
	for (int i = 0; i < n; i++)
	{
		if (visited[i]==0)
			dfs(i);
	}
	reverse(order.begin(), order.end()); //dfs���� �����ε� ����� �������� sort ���

	
	//����Ŭ�� üũ
	for (int i = 0; i < n; ++i)
	{
		
		for (int j = i + 1; j < n; ++j)
		{
			
			if (adj[order[j]][order[i]] == 1)
				return vector<int>();
		}
	}
	return order;
}