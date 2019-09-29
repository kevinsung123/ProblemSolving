#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
bool btn[10]; //0번부터 9번
int n;
int make(int x)  //만들 수 없으면 -1 만들수있으면 1이상!!
{
	if (x == 0) //0일떄 예외처치를 제대로 해줬어야한다!!!
	{
		if (btn[0]) return -1;
		else return 1;
	}

	int cnt = 0;
	while (x)
	{
		//못 누르는경우
		if (btn[x % 10]) return -1;
		//누를수있으면
		cnt++;
		x /= 10;
	}
	return cnt;
}
int main()
{

	//1억에 1초 50만개이므로 그냥 다해보자..
	int m = 0, start = 0, num_len = 0, ans = 1e9, cnt = 0;
	cin >> n;
	cin >> m;

	//리모콘 초기화 
	for (int i = 0;i < 10;i++)
	{
		btn[i] = false;
	}
	//리모콘 설정
	for (int i = 0;i < m;i++)
	{
		int tmp = 0;
		cin >> tmp;
		btn[tmp] = true;
	}
	//n이 100보다 작을때 
	//0에서 가까운지 100에서 가까운지 체크
	ans = n - 100;
	//100보다 작을때
	if (ans < 0)
		ans = -ans;

	for (int i = 0;i <= 1000000;i++)
	{
		int res = make(i);
		//만들수있을떄
		if (res != -1)
		{
			res += abs(i - n);
			ans = min(ans, res);

		}
	}

	printf("%d", ans);



}