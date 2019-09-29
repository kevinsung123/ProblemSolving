#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int arr[51][51];
int DP[51][51];
int dy[] = { 0,1,1 };
int dx[] = { 1,1,0 };
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			//좌변 길이만큼체크!
			//cnt=0 1,1 인경우 예외처리!!
			for (int cnt = 0;cnt < min(n,m);cnt++)
			{
				int check= 0;
				int length = cnt+1;
				//세변 검사
				for (int k = 0;k < 3;k++)
				{
					
					int ny = i + dy[k]*cnt;
					int nx = j + dx[k]*cnt;
					if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1) continue;
					printf("i=%d j=%d ny=%d nx=%d cnt=%d lenght=%d\n", i, j, ny, nx, cnt, length);
					if (arr[i][j] == arr[ny][nx]) check++;
				}
			
				if (check == 3)
				{
					puts("경우수 체크");
					ans = max(ans, length*length);
				}
			}
		}
	}
	printf("%d\n", ans);
}