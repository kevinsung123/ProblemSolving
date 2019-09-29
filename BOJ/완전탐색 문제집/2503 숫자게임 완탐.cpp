#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct p {
	int num;
	int s;
	int b;
	p(int num, int s, int b) :num(num), s(s), b(b) {  };
}P;

int main()
{
	int n;
	scanf("%d", &n);
	vector <P> v;
	for (int i = 0;i < n;i++)
	{
		int num, s, b;
		scanf(" %d %d %d", &num, &s, &b);
		v.push_back(P(num, s, b));
	}
	
	//��Ž!!
	int check;
	int ans = 0;
	for (check = 111; check <= 999; check++)
	{
		int a[3];
		int b[3];
		int cnt = 0;
		a[0] = check / 100, a[1] = (check / 10) % 10; a[2] = check % 10;
		if (!a[1] || !a[2] || a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) continue;
		int flag = false;
		//���������� ����
		for (int k = 0;k < v.size();k++)
		{
			int ball = 0, str = 0, t = v[k].num;
			//���� ����
			b[0] = v[k].num / 100, b[1] = v[k].num / 10 % 10, b[2] = v[k].num % 10;
			for (int p = 0;p < 3;p++)
			{
				//str üũ
				if (a[p] == b[p]) str++;
				//ball check �ڱ� ��ġ�� �ƴϸ鼭 �������� ����
				if (a[p] == b[(p + 1) % 3] || a[p] == b[(p + 2) % 3]) ball++;
			}
			if (ball == v[k].b && str == v[k].s)
			{
				cnt++;
			}
		}
		if (cnt==n)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
}