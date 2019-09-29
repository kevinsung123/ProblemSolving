#include <cstdio>
#include <stack>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long int ll;

int main() {
	int n;
	while (true)
	{
		int a[100001];
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i<n; i++) {
			scanf("%d", &a[i]);
		}

		stack<int> s;
		memset(a, 0, sizeof(a));
		ll ans = 0;
		for (int i = 0; i<n; i++) {
			int left = i;
			while (!s.empty() && a[s.top()] > a[i]) {
				int height = a[s.top()];
				s.pop();
				int width = i;
				if (!s.empty()) {
					width = (i - s.top() - 1);
				}
				if (ans < width*height) {
					ans = width * height;
				}
			}
			s.push(i);
		}
		while (!s.empty()) {
			int height = a[s.top()];
			s.pop();
			int width = n;
			if (!s.empty()) {
				width = n - s.top() - 1;
			}
			if (ans < width*height) {
				ans = width * height;
			}
		}
		printf("%lldd\n", ans);

	}
	
	return 0;
}