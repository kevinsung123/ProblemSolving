#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);
	int cnt = 1;

	//���� ������ �� �ľ����� ����������� 0�̾ƴ� �ڱ� ���� ���;��� ����ó��!
	while (true)
	{
		int a, b, c;
		a = (cnt % 15) == 0 ? 15 : cnt % 15;
		b = (cnt % 28) == 0 ? 28 : cnt % 28;
		c = (cnt % 19) == 0 ? 19 : cnt % 19;
		if (a == E && b == S && c == M) break;
		cnt++;
	}
	printf("%d\n", cnt);
}