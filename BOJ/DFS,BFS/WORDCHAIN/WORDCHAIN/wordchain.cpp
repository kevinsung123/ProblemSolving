#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

vector<string> words; //�Է� ���ڿ�
vector< vector<int> > adj; // ���ĺ��� �� ���ڿ����� �������ǥ��
vector<int> visited; //�湮����
vector<int> circuit;// ���Ϸ� ��Ŷ��
vector<string> graph[26][26]; //�������� ��Ÿ���� �ܾ��� ���(���ĺ�)
vector<int> indegree, outdegree; //������ ���� ������ ������ �� 

void makegraph(); //�׷����𵨸� (graph, adj, indegree, outdegree �ʱ�ȭ )
void getEulercircuit(int here, vector<int> circuit);
vector<int> getEulerTrailOrCircuit();
int main(void)
{
	ios::sync_with_stdio(false);
	int c; 
	cin >> c;	//�׽�Ʈ ���̽� ��
	while (c--)
	{
		int n;
		cin >> n;	//�Է¹��� ���ڿ��� 
		words.clear();
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			words.push_back(str); //�Է¹��� ���ڿ� ����
		}
		makegraph();
		getEulercircuit(0, circuit);





	}
	
}

void makegraph()
{
	//�������� �ʱ�ȭ
	for (int i = 0; i < 26;i++)
		for (int j = 0; j < 26; j++)
			graph[i][j].clear(); //������ �ܾ�� ��� �ʱ�ȭ
		adj = vector< vector<int> >(26, vector<int>(26, 0));  //������� �ʱ�ȭ
		indegree = outdegree = vector<int>(26, 0);


		for (int i = 0; i < words.size(); i++){
			int a = words[i][0] - 'a';
			int b = words[i][words[i].size() - 1] - 'a'; //���ĺ��̹Ƿ� index 0-25 
			graph[a][b].push_back(words[i]);
			adj[a][b]++; //i��j�� ������ ��
			outdegree[a]++;//a�� ���������̹Ƿ� ������ ���� +1
			indegree[b]++; //a->b �̹Ƿ� ���� ���� +1
		}
}

//adj�� �־����� ���Ϸ� ��Ŷ�� Ȥ�� Ʈ������ ���
void getEulercircuit(int here, vector<int> circuit)
{
	for (int there = 0; there < adj[here].size(); there++)
	{
		while (adj[here][there]>0)
		{
			adj[here][there]--;
			getEulercircuit(there, circuit);
		}
	}
	circuit.push_back(here);

}


//���� �׷����� ���Ϸ� Ʈ�����̳� ���Ϸ� ��Ŷ�� ã�ƺ���
vector<int> getEulerTrailOrCircuit()
{
	vector<int> circuit;

	//�켱 Ʈ������ ã�ƺ���
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i] == indegree[i] + 1)
		{
			getEulercircuit(i, circuit);
			return circuit;
		}
	}

	//��Ŷ�̴� ������ ������ �ƹ��� ȣ��
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i])  //0�̾ƴϸ� ���̹Ƿ� ������ �������ϳ��� �ִ°� 
		{
			getEulercircuit( i, circuit);
			return circuit;
		}
	}

}
//���Ϸ� ��Ŷ/Ʈ���� ��������
bool checkeuler()
{
	//���� �������� ����
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; i++)
	{
		int delta = outdegree[i] - indegree[i];
		if (delta < -1 || 1 < delta) return false;
		if (delta == 1) plus1++;
		if (delta == -1) minus1++;
	}
	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);

}


string solve(vector<string> words)
{
	//�׷��� �𵨸�
	makegraph();

	//������ ���� ������ ����
	if (!checkeuler()) return "IMPOSSIBLE";

	//���Ϸ� ��Ŷ�̳� ��θ� ã�Ƴ�
	vector<int> circuit = getEulerTrailOrCircuit();

	//��� ������ ������������ ����
	if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";  //�� +1�̳ĸ� circuit�� ����� ������γ�Ÿ���� 1���� ������
	
	reverse(circuit.begin(), circuit.end());
	string ret;

	for (int i = 1; i < circuit.size(); i++)
	{
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size()) ret += " ";
		ret += graph[a][b].back();

	}
	return ret;
}