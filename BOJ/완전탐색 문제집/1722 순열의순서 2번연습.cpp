#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, k, num;
int arr[22];
ll fact[22];  //실수!!!
int check[22];
int main()
{
	scanf("%d", &n);
	scanf("%d", &num);
	fact[0] = 1;
	for (int i = 1;i <= n;i++) fact[i] = i * fact[i - 1];
	if (num == 1)
	{
		ll k;
		scanf("%lld", &k);
		vector<int> v;
		//각각의 맨 윗자리부터 검사
		for (int i = 0;i < n;i++)
		{
			//각 자리수에대한 순서
			for (int j = 1;j <= n;j++)
			{
				if (check[j]) continue;

				if (fact[n - i - 1] < k)
				{
					k -= fact[n - 1 - i];
				}
				else
				{
					//fact[n-i-1]>k이면 그 j번째수가 있는것
					check[j] = true;
					v.push_back(j);
					break;
				}
			}
		}
		for (int i = 0;i < v.size();i++) printf("%d ", v[i]);
		printf("\n");
	}
	else
	{
		vector<int > v;
		int tmp = 0;
		for (int i = 0;i < n;i++)
		{
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		//전체자리수 맨위부터 아래로
		ll cnt = 0;
		for (int i = 0;i < n;i++)
		{
			//각자리수에대해서 1-v[i]-1까지
			// 1 3 2 4 라면 자리수 세기위해 1,3,2,4미만 수까지 세어야함.
			for (int j = 1;j < v[i]; j++)
			{
				if (check[j]) continue;

				cnt += fact[n - i - 1];
			}
			//각 자리에 숫자에대한 미만의 수를 다세고 
			//각 자리 체크!!
			check[v[i]] = true;
		}
		printf("%lld\n", cnt+1);
	}

}