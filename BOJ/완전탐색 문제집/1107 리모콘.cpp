#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
bool btn[10]; //0������ 9��
int num[10];  //���� ��¹迭
int num_len;
int n;
int make(int x)
{
	int cnt = 0;
	
	while(x)
	{

		//�� �����°��
		if (!btn[x%10]) return -1;

		//������������
		if (btn[x%10])
		{
			cnt++;
			x /= 10;
		}
	}

	return cnt;
}

int makeBig(int x)
{
	//�����鶧 �����Ѱ�� ����
	int sum = 0;
	int len = 1;
	int cnt = 0;
	int ans = 1e9;
	for (int i = 0;i < num_len;i++)
	{
		//�����ܴ�����������
		if (btn[num[i]])
		{
			sum += num[i] * len;
			cnt++;

		}
		//�����������
		else {
			int min_diff = 1e9;
			int min_idx = 0;
			int k = 0;
			for (k = 0;k < 10;k++)
			{
				//������ ������ ��ư���� �ִ��� ���̰� ������ ����
				if (btn[k])
				{
					if (min_diff > abs(num[i] - k))
					{
						min_idx = k;
						min_diff = abs(num[i] - k);
					}
				}

			}
			cnt++;
			sum += min_idx * len;
		}
		//�ڸ��� ����
		len *= 10;
	}
	//	printf("sum=%d cnt=%d", sum, cnt);
	ans = min(cnt + abs(sum - x), abs( - 100));
	return ans;
}
int main()
{
	
		int m = 0, start = 0, num_len = 0, ans = 1e9, cnt = 0;
		cin >> n;
		cin >> m;

		//������ �ʱ�ȭ 
		for (int i = 0;i < 10;i++)
		{
			btn[i] = true;
		}
		//���� ����
		int idx = 0;
		int tmp = n;
		while (tmp)
		{
			num[idx++] = tmp % 10;
			tmp /= 10;
		}
		num_len = idx;
		//������ ����
		for (int i = 0;i < m;i++)
		{
			int tmp = 0;
			cin >> tmp;
			btn[tmp] = false;
		}
		start = 100;

		//���ܼ���
		if (n <= 100)
		{
			if (n == 100)
			{
				printf("0\n");
			}
			else {
				int res = make(n);
				if (res != -1)
				{
					//������ִ°��� , +/-�̵��Ҷ�
					ans = min(ans, min(abs(n - 100), res));
				}
				else 
				{
					//������ ����
					ans = min(ans, makeBig(n));
				}
				
			}
			printf("%d", ans);
		}
		else
		{
			ans = min(makeBig(n), min(ans, make(n)) );
			printf("%d", ans);
		}
}