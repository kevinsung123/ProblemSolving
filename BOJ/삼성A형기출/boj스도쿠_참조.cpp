#include <cstdio>
#include <cstdlib>

bool row[9][10], col[9][10], squ[9][10];
int n, a[9][9], b[81];

int s(int i, int j) {
	return i / 3 * 3 + j / 3;
}

void solve(int idx) {
	if (idx == n) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	int x = b[idx] / 9, y = b[idx] % 9;
	for (int i = 1; i < 10; i++) {
		if (row[x][i] || col[y][i] || squ[s(x, y)][i]) continue;
		row[x][i] = col[y][i] = squ[s(x, y)][i] = true;
		a[x][y] = i;
		solve(idx + 1);
		a[x][y] = 0;
		row[x][i] = col[y][i] = squ[s(x, y)][i] = false;
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &a[i][j]);
			int k = a[i][j];
			if (!k) b[n++] = i * 9 + j;
			else {
				row[i][k] = true;
				col[j][k] = true;
				squ[s(i, j)][k] = true;
			}
		}
	}
	solve(0);
	return 0;
}

