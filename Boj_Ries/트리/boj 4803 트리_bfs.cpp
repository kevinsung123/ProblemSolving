#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<iterator>
using namespace std;


int N, M;
int ans;
vector<int> child[501];
int chk[501] = { 0, };

void bfs(int n)
{
	
	int node = 1;//정점의개수 
	int edge = 0;  //간선의 개수
	queue<int >q;
	chk[n] = 1;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		//현재 정점의 자식 루프 확인
		//현재 노드의 간선을 모두 다 더함
		edge += child[cur].size();
		for (int i = 0; i < child[cur].size(); i++)
		{
			int c = child[cur][i];
			if (chk[c] == 0)//아직 방문하지않았다면
			{
				q.push(c);
				chk[c] = 1;
				node++; //정점 1개찾음
			}
		}
		
	}
	// node = edge -1의 관계가 성립하면 트리라고 인정!!
	if (node == edge/2 + 1) {
		ans++;

	}


}


int main()
{
	ios::sync_with_stdio(false);
	int cnt = 0;
	while (1)
	{

		//초기화
		ans = 0;
		for (int i = 0; i < 501; i++)
		{
			if (child[i].size() > 0) child[i].clear();
		}
		memset(chk, 0, sizeof(chk));//방문배열초기화

		cin >> N >> M; 
		cnt++;
		if (N == 0 && M == 0) break;
		int a, b = 0;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			child[a].push_back(b);
			child[b].push_back(a);

		}
		//정점개수 1-N까지 트리인지확인 
		for (int i = 1; i <= N; i++)
		{
			if(chk[i]==0) bfs(i);  //아직 방문하지 않은 노드라면
		}
		if (ans == 0) cout << "Case " << cnt << ": No trees." << "\n";
		else if(ans==1) cout << "Case " << cnt << ": There is one tree." << "\n";
		else cout << "Case " << cnt << ": A forest of "<<ans<<" trees." << "\n";
	}

}