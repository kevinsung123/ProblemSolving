#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int N, M;
int parents[501];
int chk[501];  //Ʈ������
int ans;
/*
find 
- �� ���Ұ� ���� ���տ� �����ִ��� Ȯ��
- ������ ��Ʈ�� ã�Ƽ� ��
- �ڽ��� ��Ʈ�̸� ����

*/
int find(int node)
{
	//�ڱ� �ڽ��� �θ��ΰ��
	if (parents[node] ==node) return node;
	else return parents[node] = find(parents[node]);
}
/*
x,y ��� 2���� �ϳ��� ��Ʈ�� ������
�� ���� �ϳ��� ��Ʈ�� �ٸ� �ϳ��� ��Ʈ�� �ڽ��� �ǵ��Ͽ��� 

*/
void merge(int x, int y)
{
	x = find(x); // x�� ��Ʈ
	y = find(y); // y�� ��Ʈ

	// ���� �����ΰ��
	if (x == y || !chk[x] || !chk[y])
	{
		chk[x] = 0;
		chk[y] = 0;
	}



	//y�� x ����Ʈ���� ��ħ!
	parents[y] = x;
}

int main()
{
	ios::sync_with_stdio(false);
	int cnt = 1;//���̽� ��ȣ
	while (1)
	{


		//�Է� 
		cin >> N >> M;
		if (N == 0 && M == 0) break;


		//�ʱ�ȭ 
		ans = 0;
		for (int i = 1; i <= N; i++)
		{
			parents[i] = i;  //���1���� �ɷ� �ʱ�ȭ
			chk[i] = 1;  //��尡 1���� Ʈ��
		}


		int a, b;
		//M�� ������ �Է¹��� 
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			merge(a, b);
		}
		//Ʈ�����θ� �Ǵ�
		for (int i = 1; i <= N; i++)
		{
			if (chk[find(i)])// i���� ����� ��Ʈ�� ã�Ƽ� Ʈ������ Ȯ��
			{
				chk[find(i)] = false; //ó������ count�ϰ����� flag=0
				ans++;
			}
		}

		if (ans == 0) cout << "Case " << cnt << ": No trees.\n";
		else if (ans == 1) cout << "Case " << cnt << ": There is one tree.\n";
		else cout << "Case " << cnt << ": A forest of " << ans << " trees.\n";

		cnt++;

		

	}

}