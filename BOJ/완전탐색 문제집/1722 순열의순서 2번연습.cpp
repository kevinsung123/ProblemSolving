#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, k, num;
int arr[22];
ll fact[22];  //�Ǽ�!!!
int check[22];
int main()
{
	scanf("%d", &n);
	scanf("%d", &num);
	fact[0] = 1;
	for (int i = 1;i <= n;i++) fact[i] = i * fact[i - 1];
	if (num == 1)
	{
		ll k;
		scanf("%lld", &k);
		vector<int> v;
		//������ �� ���ڸ����� �˻�
		for (int i = 0;i < n;i++)
		{
			//�� �ڸ��������� ����
			for (int j = 1;j <= n;j++)
			{
				if (check[j]) continue;

				if (fact[n - i - 1] < k)
				{
					k -= fact[n - 1 - i];
				}
				else
				{
					//fact[n-i-1]>k�̸� �� j��°���� �ִ°�
					check[j] = true;
					v.push_back(j);
					break;
				}
			}
		}
		for (int i = 0;i < v.size();i++) printf("%d ", v[i]);
		printf("\n");
	}
	else
	{
		vector<int > v;
		int tmp = 0;
		for (int i = 0;i < n;i++)
		{
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		//��ü�ڸ��� �������� �Ʒ���
		ll cnt = 0;
		for (int i = 0;i < n;i++)
		{
			//���ڸ��������ؼ� 1-v[i]-1����
			// 1 3 2 4 ��� �ڸ��� �������� 1,3,2,4�̸� ������ �������.
			for (int j = 1;j < v[i]; j++)
			{
				if (check[j]) continue;

				cnt += fact[n - i - 1];
			}
			//�� �ڸ��� ���ڿ����� �̸��� ���� �ټ��� 
			//�� �ڸ� üũ!!
			check[v[i]] = true;
		}
		printf("%lld\n", cnt+1);
	}

}