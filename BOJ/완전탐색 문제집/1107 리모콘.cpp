#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
bool btn[10]; //0번부터 9번
int num[10];  //숫자 담는배열
int num_len;
int n;
int make(int x)
{
	int cnt = 0;
	
	while(x)
	{

		//못 누르는경우
		if (!btn[x%10]) return -1;

		//누를수있으면
		if (btn[x%10])
		{
			cnt++;
			x /= 10;
		}
	}

	return cnt;
}

int makeBig(int x)
{
	//못만들때 근접한경우 만듬
	int sum = 0;
	int len = 1;
	int cnt = 0;
	int ans = 1e9;
	for (int i = 0;i < num_len;i++)
	{
		//리모콘누를수있으면
		if (btn[num[i]])
		{
			sum += num[i] * len;
			cnt++;

		}
		//못누른느경우
		else {
			int min_diff = 1e9;
			int min_idx = 0;
			int k = 0;
			for (k = 0;k < 10;k++)
			{
				//가능한 리모콘 버튼으로 최대한 차이가 작은거 구함
				if (btn[k])
				{
					if (min_diff > abs(num[i] - k))
					{
						min_idx = k;
						min_diff = abs(num[i] - k);
					}
				}

			}
			cnt++;
			sum += min_idx * len;
		}
		//자릿수 증가
		len *= 10;
	}
	//	printf("sum=%d cnt=%d", sum, cnt);
	ans = min(cnt + abs(sum - x), abs( - 100));
	return ans;
}
int main()
{
	
		int m = 0, start = 0, num_len = 0, ans = 1e9, cnt = 0;
		cin >> n;
		cin >> m;

		//리모콘 초기화 
		for (int i = 0;i < 10;i++)
		{
			btn[i] = true;
		}
		//숫자 넣음
		int idx = 0;
		int tmp = n;
		while (tmp)
		{
			num[idx++] = tmp % 10;
			tmp /= 10;
		}
		num_len = idx;
		//리모콘 설정
		for (int i = 0;i < m;i++)
		{
			int tmp = 0;
			cin >> tmp;
			btn[tmp] = false;
		}
		start = 100;

		//예외설정
		if (n <= 100)
		{
			if (n == 100)
			{
				printf("0\n");
			}
			else {
				int res = make(n);
				if (res != -1)
				{
					//만들수있는경우랑 , +/-이동할때
					ans = min(ans, min(abs(n - 100), res));
				}
				else 
				{
					//근접수 만듬
					ans = min(ans, makeBig(n));
				}
				
			}
			printf("%d", ans);
		}
		else
		{
			ans = min(makeBig(n), min(ans, make(n)) );
			printf("%d", ans);
		}
}