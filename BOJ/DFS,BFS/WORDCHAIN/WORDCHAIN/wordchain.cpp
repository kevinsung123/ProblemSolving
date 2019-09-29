#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

vector<string> words; //입력 문자열
vector< vector<int> > adj; // 알파벳의 각 글자에대한 인접행렬표현
vector<int> visited; //방문여부
vector<int> circuit;// 오일러 서킷답
vector<string> graph[26][26]; //간선들이 나타내는 단어의 목록(알파벳)
vector<int> indegree, outdegree; //정점에 들어가고 나가는 간선의 수 

void makegraph(); //그래프모델링 (graph, adj, indegree, outdegree 초기화 )
void getEulercircuit(int here, vector<int> circuit);
vector<int> getEulerTrailOrCircuit();
int main(void)
{
	ios::sync_with_stdio(false);
	int c; 
	cin >> c;	//테스트 케이스 수
	while (c--)
	{
		int n;
		cin >> n;	//입력받을 문자열수 
		words.clear();
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			words.push_back(str); //입력받은 문자열 저장
		}
		makegraph();
		getEulercircuit(0, circuit);





	}
	
}

void makegraph()
{
	//전역변수 초기화
	for (int i = 0; i < 26;i++)
		for (int j = 0; j < 26; j++)
			graph[i][j].clear(); //간선인 단어들 목록 초기화
		adj = vector< vector<int> >(26, vector<int>(26, 0));  //인접행렬 초기화
		indegree = outdegree = vector<int>(26, 0);


		for (int i = 0; i < words.size(); i++){
			int a = words[i][0] - 'a';
			int b = words[i][words[i].size() - 1] - 'a'; //알파벳이므로 index 0-25 
			graph[a][b].push_back(words[i]);
			adj[a][b]++; //i와j의 간선의 수
			outdegree[a]++;//a는 나가는점이므로 나가는 차수 +1
			indegree[b]++; //a->b 이므로 들어가는 차수 +1
		}
}

//adj가 주어질때 오일러 서킷은 혹은 트레일을 계산
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


//현재 그래프의 오일러 트레일이나 오일러 서킷을 찾아본다
vector<int> getEulerTrailOrCircuit()
{
	vector<int> circuit;

	//우선 트레일을 찾아본다
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i] == indegree[i] + 1)
		{
			getEulercircuit(i, circuit);
			return circuit;
		}
	}

	//서킷이니 간선에 인접한 아무나 호출
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i])  //0이아니면 참이므로 간선이 무조건하나는 있는거 
		{
			getEulercircuit( i, circuit);
			return circuit;
		}
	}

}
//오일러 서킷/트레일 존재유무
bool checkeuler()
{
	//예비 시작점과 끝수
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
	//그래프 모델링
	makegraph();

	//차수가 맞지 않으면 실패
	if (!checkeuler()) return "IMPOSSIBLE";

	//오일러 서킷이나 경로를 찾아냄
	vector<int> circuit = getEulerTrailOrCircuit();

	//모든 간선을 가지못했으면 실패
	if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";  //왜 +1이냐면 circuit의 결과가 정점들로나타나서 1개더 쓰여짐
	
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