#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
#define MAX 100001

int parent[MAX];  //부모
int chk[MAX];	  //확인 부모노드를 결정하는  방문배열
vector<int> child[MAX];//자식리스트  => 이지트리가 아니라 k지트리라고 가정 
int N;//노드의 개수

int main()
{

	ios::sync_with_stdio(false);
	cin >> N;
	int a, b;
	for (int i = 1; i <= N - 1; i++)
	{
		cin >> a >> b;
		child[a].push_back(b);
		child[b].push_back(a);
	}

	chk[1] = 1;//루트노드 방문여부
	queue<int>q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int m = 0; m < child[cur].size(); m++)
		{
			int c = child[cur][m];
			if (chk[c] == 0)  //아직 방문하지않았다면
			{
				q.push(c);
				parent[c] = cur; //부모노드지정
				chk[c] = 1; //방문처리
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}
	
}