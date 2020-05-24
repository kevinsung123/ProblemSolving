#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int N, M;
int parents[501];
int chk[501];  //트리여부
int ans;
/*
find 
- 두 원소가 같은 집합에 속해있는지 확인
- 각각의 루트를 찾아서 비교
- 자신이 루트이면 리턴

*/
int find(int node)
{
	//자기 자신이 부모인경우
	if (parents[node] ==node) return node;
	else return parents[node] = find(parents[node]);
}
/*
x,y 노드 2개를 하나의 루트로 합쳐줌
둘 중의 하나의 루트를 다른 하나의 루트의 자식이 되도록연결 

*/
void merge(int x, int y)
{
	x = find(x); // x의 루트
	y = find(y); // y의 루트

	// 같은 집합인경우
	if (x == y || !chk[x] || !chk[y])
	{
		chk[x] = 0;
		chk[y] = 0;
	}



	//y를 x 서브트리에 합침!
	parents[y] = x;
}

int main()
{
	ios::sync_with_stdio(false);
	int cnt = 1;//케이스 번호
	while (1)
	{


		//입력 
		cin >> N >> M;
		if (N == 0 && M == 0) break;


		//초기화 
		ans = 0;
		for (int i = 1; i <= N; i++)
		{
			parents[i] = i;  //노드1개인 걸로 초기화
			chk[i] = 1;  //노드가 1개인 트리
		}


		int a, b;
		//M개 간선을 입력받음 
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			merge(a, b);
		}
		//트리여부를 판단
		for (int i = 1; i <= N; i++)
		{
			if (chk[find(i)])// i번쨰 노드의 루트를 찾아서 트리인지 확인
			{
				chk[find(i)] = false; //처음으로 count하고나서는 flag=0
				ans++;
			}
		}

		if (ans == 0) cout << "Case " << cnt << ": No trees.\n";
		else if (ans == 1) cout << "Case " << cnt << ": There is one tree.\n";
		else cout << "Case " << cnt << ": A forest of " << ans << " trees.\n";

		cnt++;

		

	}

}