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

	//1.ù���� ���
	//�ּ� �Ѱ��� �����ؾ��Ѵ�
	//�Է��ؾ��ϴ� ���� �Ѱ��� ����� ������ flag=false=>absmax
	//��� ������� flag=true�� �׳� �ּ� �Ѱ� �����Ѱ��� ���
	//for (int i = 0; i<N; i++) {
	//	scanf("%d", &n);
	//	if (n > 0) flag = false;
	//	if (Max < n) Max = n;
	//	locMax += n;
	//	if (locMax < 0) locMax = 0;
	//	else if (locMax > absMax) absMax = locMax;
	//}
	//printf("%d\n", flag ? Max : absMax);

	//2���� ��� dp! dp[i]=dp[i-1]+arr[i] �� arr[i]�� �� �Ͽ� ū ���� �ִ´�
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
	
	//3��° ��� dp
	//������ �Ȱ��� ���簪�� ������+���簪�� ���Ͽ� ����!
	long long max = -1e15;
	for (int i = 1;i <= N;i++) {
		scanf("%d", &d[i]);
		d[i] = d[i] + d[i - 1]>d[i] ? d[i] + d[i - 1] : d[i];
		max = d[i]>max ? d[i] : max;
	}
	printf("%lld", max);
	return 0;
}