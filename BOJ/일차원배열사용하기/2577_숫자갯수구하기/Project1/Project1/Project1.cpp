#include<cstdio>
#include<string>
int main()
{
	int a, b, c, mul, idx;
	int cnt[10] = { 0 };
	scanf("%d %d %d", &a, &b, &c);
	mul = a*b*c;
	//printf("mul=%d\n", mul);
	while (mul >0)
	{
		idx = mul % 10;
		//printf("idx=%d\n", idx);
		cnt[idx]++;
		mul /= 10;
	}

	for (int i = 0;i < 10;i++)
		printf("%d\n", cnt[i]);
    return 0;
}

