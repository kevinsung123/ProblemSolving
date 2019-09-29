#include <cstdio>
#include <queue>
#include<cstring>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int roff[4] = { -1, 1, 0, 0 };
const int coff[4] = { 0, 0, -1, 1 };

int main() {
	int N, M;
	bool map[1000][1000];
	freopen("벽부수고이동하기.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
			scanf("%1d", &map[i][j]);

	bool visited[2][1000][1000] = { 0 };
	visited[0][0][0] = true;
	queue<int> Q;
	Q.push(0);
	int result = 1;

	while (!Q.empty()) {
		int qSize = Q.size();
		bool reach = false;
		printf("leve=%d\n", result);
		for (int i = 0; i<qSize; i++) {
			/*
			매 상태는 crash, r, c 세 개의 값의 해시값으로 나타냄
			crash는 벽을 하나 부쉈는지의 여부. false면 아직 안 부숨
			*/
			bool crash = Q.front() / (N*M);
			int r = Q.front() % (N*M) / M;
			int c = Q.front() % M;
			Q.pop();
			printf("crash=%d y=%d x=%d\n", crash, r, c);
			// 도착점에 온 경우. reach를 set하고 빠져나옴
			if (r == N - 1 && c == M - 1) {
				reach = true;
				break;
			}

			// 4개 방향을 offset 배열과 반복문으로 구현
			for (int d = 0; d<4; d++) {
				int nr = r + roff[d];
				int nc = c + coff[d];
				if (nr<0 || nr >= N || nc<0 || nc >= M) continue;
				if (visited[crash][nr][nc]) continue;
				// 다음 지점이 벽이고 아직 안 부쉈다면 부수고 간다
				if (map[nr][nc]) {
					if (crash) continue;
					visited[1][nr][nc] = true;
					Q.push(N*M + nr * M + nc);
				}
				// 벽이 아닌 경우 그냥 이동
				else {
					visited[crash][nr][nc] = true;
					Q.push(crash*N*M + nr * M + nc);
				}
			}
		}

		// 도착했다면 루프를 빠져나가고, 아니면 이동 횟수 증가
		if (reach) break;
		result++;
	}
	// 도착한 경우. 이 if문은 reach를 넣어도 된다.
	if (visited[0][N - 1][M - 1] || visited[1][N - 1][M - 1]) printf("%d\n", result);
	// 도착하지 못한 경우
	else puts("-1");
}

