#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

vector< vector<int> > adj; //인접행렬
vector<int> visited; //방문여부
vector<int> order;//정렬 결과
vector<string> words;//입력받은 문자열들
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
		words.clear();//문자열 입력받기전 초기화
		order.clear();
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			words.push_back(str); 

		}
	
		makegraph(); //그래프 모델링하기
		
		vector<int> ans = topologysort(); //정렬 결과
	
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
	adj.clear(); //새로운 인접행렬만들시 초기화
	adj = vector< vector<int> >(26, vector<int>(26, 0)); //알파벳크기의 26*26 이차원배열 만듬

	for (int j = 1; j < words.size(); j++)  //실수한부분!!!!! n이 아니라 words크기만큼 돌아야함
	{
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());
	
		for (int k = 0; k < len; k++) 
		{
			if (words[i][k] != words[j][k])  //i가 앞에, j가 뒤에 문자열
			{
				int a = words[j][k] - 'a';
				int b = words[i][k] - 'a';
				adj[a][b] = 1; //adj[i][j]=1이면 i가 j보다 앞에 와야한다
				break; //이게 없으면 words[i][k]의 다른부분을 비교하므로 vector subscript range error
			}
		}
	}
}

void  dfs(int here)
{

	visited[here] = 1;//here의 정점을 방문
	
	for (int there = 0; there < adj.size(); ++there)  //vertex수만큼 for문 
	{
		if (visited[there] == 0 && adj[here][there]==1) //다른 모든정점을 확인하는데 방문하지않고 간선이 있는 경우의 정점만 방문
			dfs(there);
	}
	order.push_back(here);//dfs가 종료되는 순서대로 집어 넣음  
	//이 부분에서 실수!!!!!!!!there가 아니라 here을 넣어야함..
}
//adj인접행렬을 가지고 topologysort를 한다
vector<int> topologysort()
{
	int n = adj.size();
	visited = vector<int>(n, 0);
	order.clear();//새로운 테스트케이스시 order를 초기화
	
	//모든정점을 순환
	for (int i = 0; i < n; i++)
	{
		if (visited[i]==0)
			dfs(i);
	}
	reverse(order.begin(), order.end()); //dfs종룔 순서로된 결과를 뒤집은게 sort 결과

	
	//사이클링 체크
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