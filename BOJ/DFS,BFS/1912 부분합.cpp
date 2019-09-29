#include<climits>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
#define MAX 100001
int arr[MAX];
int cache[MAX];
int d[MAX];
int main() {

	int N, n, Max = INT_MIN, locMax = 0, absMax = 0;
	bool flag = true;
	int ans = 0;
	scanf("%d", &N);

	//1.첫번쨰 방법
	//최소 한개는 선택해야한다
	//입력해야하는 수중 한개라도 양수가 있으면 flag=false=>absmax
	//모두 음수라면 flag=true라서 그냥 최소 한개 선택한것을 출력
	//for (int i = 0; i<N; i++) {
	//	scanf("%d", &n);
	//	if (n > 0) flag = false;
	//	if (Max < n) Max = n;
	//	locMax += n;
	//	if (locMax < 0) locMax = 0;
	//	else if (locMax > absMax) absMax = locMax;
	//}
	//printf("%d\n", flag ? Max : absMax);

	//2번쨰 방법 dp! dp[i]=dp[i-1]+arr[i] 와 arr[i]를 비교 하여 큰 값을 넣는다
	/*for (int i = 0;i < N;i++)
	{
		scanf("%d", &arr[i]);
	}
	cache[0] = arr[0];
	ans = cache[0];
	for (int i = 1;i < N;i++)
	{
		cache[i] = max(cache[i - 1] + arr[i], arr[i]);
	}
	for (int i = 0;i < N;i++) ans = max(ans, cache[i]);

	printf("%d\n", ans);*/
	
	//3번째 방법 dp
	//원리는 똑같다 현재값과 이전값+현재값을 비교하여 갱신!
	long long max = -1e15;
	for (int i = 1;i <= N;i++) {
		scanf("%d", &d[i]);
		d[i] = d[i] + d[i - 1]>d[i] ? d[i] + d[i - 1] : d[i];
		max = d[i]>max ? d[i] : max;
	}
	printf("%lld", max);
	return 0;
}