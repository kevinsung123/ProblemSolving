#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll a, b, tmp;
ll n;
ll cnt;
int main()
{
	scanf("%lld", &n);

	//n���� 5�ǰ����� ã�¹����� ����������
	//2�� 5�ǰ����� ���� ���� ������ 
	int five = 0, two = 0;
	for (int i = 1;i <= n;i++)
	{
		tmp = i;
		while (tmp)
		{
			if (tmp % 2 == 0)
			{
				two++;tmp /= 2;
			}
			else break;
		}
		tmp = i;
		while (tmp)
		{
			if (tmp % 5 == 0)
			{
				five++;tmp /= 5;
			}
			else break;
		}
	}
	printf("%d\n", min(two, five));

	//5�� �������� ����Ͽ� 5�ǰ����� �˾Ƴ���

	for (int i = 5;i <= n;i *= 5)
		cnt += n / i;
	printf("%d\n", cnt);
}