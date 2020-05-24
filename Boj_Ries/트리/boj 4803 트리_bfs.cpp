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
	
	int node = 1;//�����ǰ��� 
	int edge = 0;  //������ ����
	queue<int >q;
	chk[n] = 1;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		//���� ������ �ڽ� ���� Ȯ��
		//���� ����� ������ ��� �� ����
		edge += child[cur].size();
		for (int i = 0; i < child[cur].size(); i++)
		{
			int c = child[cur][i];
			if (chk[c] == 0)//���� �湮�����ʾҴٸ�
			{
				q.push(c);
				chk[c] = 1;
				node++; //���� 1��ã��
			}
		}
		
	}
	// node = edge -1�� ���谡 �����ϸ� Ʈ����� ����!!
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

		//�ʱ�ȭ
		ans = 0;
		for (int i = 0; i < 501; i++)
		{
			if (child[i].size() > 0) child[i].clear();
		}
		memset(chk, 0, sizeof(chk));//�湮�迭�ʱ�ȭ

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
		//�������� 1-N���� Ʈ������Ȯ�� 
		for (int i = 1; i <= N; i++)
		{
			if(chk[i]==0) bfs(i);  //���� �湮���� ���� �����
		}
		if (ans == 0) cout << "Case " << cnt << ": No trees." << "\n";
		else if(ans==1) cout << "Case " << cnt << ": There is one tree." << "\n";
		else cout << "Case " << cnt << ": A forest of "<<ans<<" trees." << "\n";
	}

}