#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	int arr[10003];
	int psum[10003];
	for (int i = 1;i <= N;i++)
	{
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	
	int p1 = 0, p2 = 0, sum = 0, ans = 0;
	//1 투포인터
	while (1)
	{
		if (sum >= M)sum -= arr[p1++];
		else if (p2 == N) break;
		else sum += arr[p2++];
		if (sum == M)
		{
			printf("p1=%d p2=%d\n", p1, p2);
			ans++;
		}
	}

	//2 구간합+투포인터
	//idx from 0 to n-1까지
	//
	//while (!(p1==p2 && p1==N))
	//{ 
	//	//p1에서 p2까지합 포함
	//	if (psum[p2] - psum[p1-1]>=M) p1++;
	//	else
	//	{
	//		if (p2 < N)p2++;
	//		else p1++;
	//	}
	//	//printf("p2=%d p1=%d p1-1=%d sum=%d\n", p2, p1, p1 - 1,psum[p2]-psum[p1-1]);
	//	if (psum[p2] - psum[p1-1] == M)ans++;
	//
	//}
	printf("%d\n", ans);

}