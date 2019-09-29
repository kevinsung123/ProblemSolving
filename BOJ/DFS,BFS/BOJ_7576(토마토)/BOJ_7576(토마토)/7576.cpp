#include<iostream>
#include<vector>
#include<utility>  // pair
#include<queue>
#include<algorithm>  //sort 
using namespace std;

int visited[30][30]; //방문여부
int map[30][30]; //맵
int N; //입력받는 크기
void bfs(int i, int j);
vector<int> housenum; // 단지내 집의수
int groupnum = -1; //총 단지수
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int main(void)
{
	ios::sync_with_stdio(false);

	cin >> N;
	
	queue<int> q;
	cout << q.empty() << endl;
	cout << !q.empty() << endl;
	
	//map 입력받음
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	//맵을 돌면서 bfs로 순회
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == 0) //집이 있고 방문하지않았다면 순회
			{
				visited[i][j] = 1; //방문
				groupnum++; //단지수 1 증가 -1에서 1증가면 0부터 시작 map에 만족하는 곳에 bfs를 돌때마다 단지수가 1개씩 증가
				housenum.push_back(1);
				bfs(i, j);
			}
		}
	}

	sort(housenum.begin(), housenum.end()); //sort위해 begin, end를 써서 반복자 반환
	cout << housenum.size() << endl;


}


void bfs(int i, int j)
{
	visited[i][j] = 1; //방문
	queue <pair<int, int> > q; //bfs를 사용할 queue 선언
	q.push({ i, j }); // i,j인 좌표를 pair로 만들어 queue에 삽입

	while (!q.empty()){  //q가 empty이면 true=1 empty가 아니면 false=0이  !0=1  !그이외값 =0
		
		int nx = q.front().first; //x좌표
		int ny = q.front().second; //y좌표
		q.pop();//참조하므로 pop시킴
		for (int i = 0; i < 4; i++){
			nx += dx[i];
			ny += dy[i];

			if (map[nx][ny] == 0) continue; //맵이 없으면 for로 다시

			if (nx<0 || ny>0 || nx >N - 1 || ny > N - 1) continue; //맵을 벗어나면 continue
			
			if (nx >= 0 && ny >= 0 && nx < N - 1 && ny <= N - 1){
				housenum[groupnum]++; //단지내 집의수 증가
				visited[nx][ny] = 1; //순회 했으므로 방문 
				q.push({ nx, ny }); //q에 삽입 
			}


		}
			

	}
}