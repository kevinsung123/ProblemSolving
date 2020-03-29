#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<utility>
#include<cstring>
using namespace std;
#define MAX 1000000
int N, M, K;
int r, c, s;
int map[51][51]; //�� ����
int tmp[51][51]; //�ӽ�����
vector<pair<int, pair<int, int>>> rot;  //��������
int ans;
int vis[51];
int match[6];
void print()
{

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}


void copy()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) tmp[i][j] = map[i][j];
	}

}
void restore()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) map[i][j] = tmp[i][j];
	}

}
int getMin()
{
	int ret = MAX;
	//������ ���鼭 �ּڰ��� ���Ͽ� ����
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		//���� ���鼭 sum������
		for (int j = 1; j <= M; j++)
		{
			sum += map[i][j];
		}
		ret = min(ret, sum);

	}

	return ret;
}
void rotate(int r, int c, int s) //y,x, ����
{

	
	int cnt = s ;//ȸ���� �ݺ��� Ƚ��
	while (cnt > 0)
	{
		//ù��°���Ҵ� �����ߴٰ� �������� ����
		int tmp = map[r - cnt][c - cnt];
		//�ݽð�������� ����
		//��->��->��>��
		//�� x��ǥ�� ����
		for (int y = r - cnt; y < r + cnt; y++)
		{
			map[y][c - cnt] = map[y + 1][c - cnt];
		}
		//cout << "�� =====" << "\n";
		//print();
		//�� y��ǥ����
		for (int x = c - cnt; x < c + cnt; x++)
		{
			map[r + cnt][x] = map[r + cnt][x + 1];
		}
		//cout << "�� =====" << "\n";
		//print();
		//�� x��ǥ����
		for (int y = r + cnt; y > r - cnt; y--)
		{
			map[y][c + cnt] = map[y - 1][c + cnt];
		}
		//cout << "�� =====" << "\n";
		//print();
		//�� y��ǥ����
		for (int x = c + cnt; x > c - cnt; x--)
		{
			map[r - cnt][x] = map[r - cnt][x - 1];

		}

		map[r - cnt][c - cnt + 1] = tmp;
		//cout << "�� =====" << "\n";
		//print();

		cnt--;
	}
}
void solve(int idx)
{
	//k���������� �ּڰ� ���ؼ� ���Ͽ� ����
	if (idx == K)
	{	
		//ȸ�� ������ ��� �������ڿ� ������
		//�ʱ���·� ���� �� ����!
		restore(); 
		for (int i = 0; i < K; i++)
		{
			//cout << match[i] << "\n";
			int idx = match[i];
			int r,c,s;
			r = rot[idx].second.first;
			c = rot[idx].second.second;
			s = rot[idx].first;
			rotate(r, c, s);

		}

		ans = min(ans, getMin());
		return;
	}
	for (int i = 0; i < K; i++)
	{
		if (vis[i] == 0)
		{
			int r, c, s;
			s = rot[i].first; //����
			r = rot[i].second.first; //y
			c = rot[i].second.second; //x

			vis[i] = 1;
			//ȸ���� ������ �� �����ְ� ������!
			match[idx] = i;
			solve(idx + 1);
			vis[i] = 0;
			
		
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			cin >> map[y][x];
			tmp[y][x] = map[y][x];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int r, c, s;
		cin >> r >> c >> s;
		rot.push_back({ s,{r,c} });
	}
	//ans �ʱ�ȭ
	ans = 1e9;
	//�ʱⰪ �ʰ��� ���� �صе�, ȸ�������� restore�Ѵ�
	copy();
	solve(0);
	cout << ans << "\n";
}