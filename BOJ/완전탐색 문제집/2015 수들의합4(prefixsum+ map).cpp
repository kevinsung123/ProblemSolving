#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
map<int, int > mp;
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int psum[200003];
	memset(psum, 0, sizeof(psum));
	for (int i = 1;i <= n;i++)
	{
		int tmp;
		scanf("%d", &tmp);
		psum[i] = psum[i - 1] + tmp;
	}
	int ans = 0;
	// psum[i]-psum[j]=k인 i,j를 찾는것 j를찾자
	for (int i = 1;i <= n;i++)
	{
		if (psum[i] == k) ans++;
		ans += mp[psum[i] - k];
		mp[psum[i]]++;

	}
	printf("%d\n", ans);
}