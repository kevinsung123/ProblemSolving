#include<iostream>
#include<vector>
#include<utility>  // pair
#include<queue>
#include<algorithm>  //sort 
using namespace std;

int visited[30][30]; //�湮����
int map[30][30]; //��
int N; //�Է¹޴� ũ��
void bfs(int i, int j);
vector<int> housenum; // ������ ���Ǽ�
int groupnum = -1; //�� ������
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int main(void)
{
	ios::sync_with_stdio(false);

	cin >> N;
	
	queue<int> q;
	cout << q.empty() << endl;
	cout << !q.empty() << endl;
	
	//map �Է¹���
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	//���� ���鼭 bfs�� ��ȸ
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == 0) //���� �ְ� �湮�����ʾҴٸ� ��ȸ
			{
				visited[i][j] = 1; //�湮
				groupnum++; //������ 1 ���� -1���� 1������ 0���� ���� map�� �����ϴ� ���� bfs�� �������� �������� 1���� ����
				housenum.push_back(1);
				bfs(i, j);
			}
		}
	}

	sort(housenum.begin(), housenum.end()); //sort���� begin, end�� �Ἥ �ݺ��� ��ȯ
	cout << housenum.size() << endl;


}


void bfs(int i, int j)
{
	visited[i][j] = 1; //�湮
	queue <pair<int, int> > q; //bfs�� ����� queue ����
	q.push({ i, j }); // i,j�� ��ǥ�� pair�� ����� queue�� ����

	while (!q.empty()){  //q�� empty�̸� true=1 empty�� �ƴϸ� false=0��  !0=1  !���̿ܰ� =0
		
		int nx = q.front().first; //x��ǥ
		int ny = q.front().second; //y��ǥ
		q.pop();//�����ϹǷ� pop��Ŵ
		for (int i = 0; i < 4; i++){
			nx += dx[i];
			ny += dy[i];

			if (map[nx][ny] == 0) continue; //���� ������ for�� �ٽ�

			if (nx<0 || ny>0 || nx >N - 1 || ny > N - 1) continue; //���� ����� continue
			
			if (nx >= 0 && ny >= 0 && nx < N - 1 && ny <= N - 1){
				housenum[groupnum]++; //������ ���Ǽ� ����
				visited[nx][ny] = 1; //��ȸ �����Ƿ� �湮 
				q.push({ nx, ny }); //q�� ���� 
			}


		}
			

	}
}