#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
bool btn[10]; //0������ 9��
int n;
int make(int x)  //���� �� ������ -1 ����������� 1�̻�!!
{
	if (x == 0) //0�ϋ� ����óġ�� ����� �������Ѵ�!!!
	{
		if (btn[0]) return -1;
		else return 1;
	}

	int cnt = 0;
	while (x)
	{
		//�� �����°��
		if (btn[x % 10]) return -1;
		//������������
		cnt++;
		x /= 10;
	}
	return cnt;
}
int main()
{

	//1�￡ 1�� 50�����̹Ƿ� �׳� ���غ���..
	int m = 0, start = 0, num_len = 0, ans = 1e9, cnt = 0;
	cin >> n;
	cin >> m;

	//������ �ʱ�ȭ 
	for (int i = 0;i < 10;i++)
	{
		btn[i] = false;
	}
	//������ ����
	for (int i = 0;i < m;i++)
	{
		int tmp = 0;
		cin >> tmp;
		btn[tmp] = true;
	}
	//n�� 100���� ������ 
	//0���� ������� 100���� ������� üũ
	ans = n - 100;
	//100���� ������
	if (ans < 0)
		ans = -ans;

	for (int i = 0;i <= 1000000;i++)
	{
		int res = make(i);
		//�����������
		if (res != -1)
		{
			res += abs(i - n);
			ans = min(ans, res);

		}
	}

	printf("%d", ans);



}