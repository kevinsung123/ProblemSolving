#include<cstdio>
int n, d[26], i, t, j, a;
char in[102];
int main() {
	scanf("%d", &t);
	for (j = 1;j <= t;j++) {
		scanf("%s", in);
		d[in[0] - 'a'] = j;
		for (i = 1;in[i];i++) {
			if (in[i - 1] != in[i] && d[in[i] - 'a'] == j)break;
			d[in[i] - 'a'] = j;
		}
	/*	printf("i=%d j=%d\n", i,j);
		for (int i = 0;i < 26;i++)
			printf("%d ", d[i]);
		printf("\n");*/

		if (!in[i])a++;
	}
	printf("%d", a);
}