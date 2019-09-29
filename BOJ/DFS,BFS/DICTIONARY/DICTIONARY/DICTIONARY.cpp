#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

//DAG(Directed Acyclic Graph) 순환이없는 그래프
vector< vector<int> > adj; //알파벳의 각 글자에 대한 인접행렬표현
vector<string> words;//입력받은 글자를저장하는 벡터

//정점 방문 여부
vector<int> seen;

//위상정렬 결과
vector<int> order;
//그래프 생성 
void makegraph();
//위상정렬
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
		int n;//단어의수 
		cin >> n;
		words.clear(); //clear
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			words.push_back(str);
			
		}
		//adj 인접행렬에 그래프를 만든다 dag
		makegraph();
		
	
	/*	for (size_t i = 0; i < adj.size(); i++){
		for (size_t j = 0; j < adj[i].size(); j++)
		cout << adj[i][j] << " ";
		cout << endl;
		}*/
		//topologysort된 vector를 만든다
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
		int len = min(words[i].size(), words[j].size()); //길이가 더 짧은 것을 구함
		//words[i]가 words[j]보다 앞에 오는 이유를 찾는다
		for (int k = 0; k < len; k++)
		{
			if (words[i][k] != words[j][k]){
				int a = words[i][k] - 'a'; //아스키 코드표로 A=65 a=97
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
	seen[here] = 1; //here에 방문
	for (int there = 0; there < adj.size(); ++there)  //adj의 사이즈는 26 모든 alphabet 정점을 순환
	{
		if (adj[here][there]==1 && seen[there]==0) //adj[i][j]는 i가 j보다 앞에나오면서 visited[j]에 방문한적이 없으면 dfs로 방문
			dfs(there);
	}
	order.push_back(here); //dfs가 끝난 결과 순서대로 위상정렬결과 order에 넣는다 이 순서의 반대가 위상정렬 결과

}

vector<int> topologysort()
{
	int n = adj.size();//alphabet 26
	seen = vector<int>(n, 0); //26 크기의 vector를 0으로 초기화1
	order.clear(); //topology 결과를 clear 각각의 case마다 order를 쓰므로 초기화시켜주자!
	//각각의 정점들을 dfs로 돌면서 dfs 종료된 순서대로 
	for (int i = 0; i < n; ++i)
	{
		if (seen[i]==0) //아직 방문하지않았다면
			dfs(i);
	}
	reverse(order.begin(), order.end());
	//만약 그래프가DAG가 아니라면 정렬 결과에 역방향 간선이 있다 사이클링 검사
	for (int i = 0; i < n; ++i){
		for (int j = i + 1; j < n; ++j)
		{
			if (adj[order[j]][order[i]]==1)
				return vector<int>(); //empty 벡터 반환 사이클링이 있다면
		}
	}
	//없는 경우라면
	return order;
}