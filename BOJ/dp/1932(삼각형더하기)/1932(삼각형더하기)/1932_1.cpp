#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500

int map[MAX][MAX] = { 0, };

int main(void){
	
	int T;	
	
	cin >> T;

	for (int i = 0; i < T; i++){
		for (int j = 0; j <= i; j++){
			cin >> map[i][j];
		}
	}

	
	int sum[MAX][MAX] = { 0 };

	for (int i = 0; i < T; i++){
		for (int j = 0; j <= i; j++){
			if (i == 0 && j == 0)
				map[i][j] = map[0][0];
			else if (j == 0)
				map[i][j] += map[i - 1][j];
			else if (i == j)
				map[i][j] += map[i - 1][j - 1];
			else
				map[i][j] = max(map[i][j] + map[i - 1][j - 1], map[i][j] + map[i - 1][j]);
		}
	}

	
	int Ans = -1;
	//맨 밑에 행의 값들중 최대값을 출력
	for (int i = 0; i < T; i++)
		Ans= max(map[T - 1][i], Ans);


	cout << Ans;
}