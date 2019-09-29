#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

//DAG(Directed Acyclic Graph) ��ȯ�̾��� �׷���
vector< vector<int> > adj; //���ĺ��� �� ���ڿ� ���� �������ǥ��
vector<string> words;//�Է¹��� ���ڸ������ϴ� ����

//���� �湮 ����
vector<int> seen;

//�������� ���
vector<int> order;
//�׷��� ���� 
void makegraph();
//��������
vector<int> topologysort();
//dfs
void dfs(int here);

int main(void)
{
	ios::sync_with_stdio(false);
	int c; //test case
	cin >> c;
	while (c--)
	{
		int n;//�ܾ��Ǽ� 
		cin >> n;
		words.clear(); //clear
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			words.push_back(str);
			
		}
		//adj ������Ŀ� �׷����� ����� dag
		makegraph();
		
	
	/*	for (size_t i = 0; i < adj.size(); i++){
		for (size_t j = 0; j < adj[i].size(); j++)
		cout << adj[i][j] << " ";
		cout << endl;
		}*/
		//topologysort�� vector�� �����
		vector<int> ans = topologysort();
		
		if (ans.empty()) cout << "invalid hypothesis" << endl;
		else{
			for (int i = 0; i < ans.size(); i++)
				cout << (char)(ans[i] + 'a');
		}
		cout << endl;
 	}

	return 0;
}

void makegraph()
{
	adj.clear();
	adj = vector < vector<int> >(26, vector<int>(26, 0));

	for (int j = 1; j < words.size(); ++j){
		int i = j - 1;
		int len = min(words[i].size(), words[j].size()); //���̰� �� ª�� ���� ����
		//words[i]�� words[j]���� �տ� ���� ������ ã�´�
		for (int k = 0; k < len; k++)
		{
			if (words[i][k] != words[j][k]){
				int a = words[i][k] - 'a'; //�ƽ�Ű �ڵ�ǥ�� A=65 a=97
				int b = words[j][k] - 'a';
			//	cout << char(a+'a') << " " << char(b+'a') << endl;
				adj[a][b] = 1;
				break;
			}
		}
	}
}
void dfs(int here)
{
	seen[here] = 1; //here�� �湮
	for (int there = 0; there < adj.size(); ++there)  //adj�� ������� 26 ��� alphabet ������ ��ȯ
	{
		if (adj[here][there]==1 && seen[there]==0) //adj[i][j]�� i�� j���� �տ������鼭 visited[j]�� �湮������ ������ dfs�� �湮
			dfs(there);
	}
	order.push_back(here); //dfs�� ���� ��� ������� �������İ�� order�� �ִ´� �� ������ �ݴ밡 �������� ���

}

vector<int> topologysort()
{
	int n = adj.size();//alphabet 26
	seen = vector<int>(n, 0); //26 ũ���� vector�� 0���� �ʱ�ȭ1
	order.clear(); //topology ����� clear ������ case���� order�� ���Ƿ� �ʱ�ȭ��������!
	//������ �������� dfs�� ���鼭 dfs ����� ������� 
	for (int i = 0; i < n; ++i)
	{
		if (seen[i]==0) //���� �湮�����ʾҴٸ�
			dfs(i);
	}
	reverse(order.begin(), order.end());
	//���� �׷�����DAG�� �ƴ϶�� ���� ����� ������ ������ �ִ� ����Ŭ�� �˻�
	for (int i = 0; i < n; ++i){
		for (int j = i + 1; j < n; ++j)
		{
			if (adj[order[j]][order[i]]==1)
				return vector<int>(); //empty ���� ��ȯ ����Ŭ���� �ִٸ�
		}
	}
	//���� �����
	return order;
}