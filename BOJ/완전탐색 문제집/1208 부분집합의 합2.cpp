#include<stdio.h>
#include<map>
using namespace std;
int n, s, a[20];
map<int, int> mp;
int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n / 2; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 1 << n / 2; i++) {
		int sum = 0;
		for (int j = 0; j < n / 2; j++) sum += (i >> j) % 2 * a[j];
		mp[sum]++;
	}
	for (int i = n / 2; i <n; i++)
		scanf("%d", &a[i - n / 2]);
	long long res = 0;
	for (int i = 0; i < 1 << n - n / 2; i++) {
		int sum = 0;
		for (int j = 0; j < n - n / 2; j++) sum += (i >> j) % 2 * a[j];
		res += mp[s - sum];
	}
	if (!s) res--;
	printf("%lld", res);
	return 0;
}