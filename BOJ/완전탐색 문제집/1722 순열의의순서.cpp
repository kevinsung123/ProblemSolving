#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
bool check[22];
ll fact[22] = { 1, };
int cnt, ans;
ll k;
int num, n;

int main()
{
	scanf("%d %d", &n,&num);
	

	//���丮�� ���ϱ�
	for (int i = 1;i <= n;i++)
	{
		fact[i] = i*fact[i - 1];
	}
	if (num == 1)
	{
		ll k = 0;
		scanf("%lld", &k);
		vector<int> v;
		for (int i = 0;i < n;i++)
		{
			//1-n���� �� ���� Ȯ��
			for (int j = 1;j <= n;j++)
			{
				//�̹� �ִ� ���� üũ
				if (check[j]) continue;
				//k���� ������ �� ���� ������ ���丱�� �߰�
				if (fact[n - i - 1] < k) k -= fact[n - i - 1];
				//k���� ũ��
				else {

					check[j] = true;
					v.push_back(j);
					break; //�� �ڸ����� �������Ƿ� break;
				}
			}
		}
		for (auto x : v) printf("%d ", x);
		printf("\n");
	}
	else
	{
		vector<int> v;
		int tmp = 0;
		ll cnt = 0;
		for (int i = 0;i < n;i++)
		{
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		//���� �ٸ� �ڸ���
		for (int i = 0;i < n;i++)
		{
			//�Է¹��� �� ã�°���
			//���� �ڸ��� �ٸ� ����
			for (int j = 1;j < v[i];j++)
			{
				//�̹� �湮
				if (check[j]) continue;

				cnt += fact[n - i - 1];


			}
			//�� ���� �湮 ǥ��
			check[v[i]] = true;
		}
		printf("%lld\n", cnt+1);
	}

	return 0;
}