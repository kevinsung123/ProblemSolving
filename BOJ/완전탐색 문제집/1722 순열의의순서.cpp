#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
bool check[22];
ll fact[22] = { 1, };
int cnt, ans;
ll k;
int num, n;

int main()
{
	scanf("%d %d", &n,&num);
	

	//팩토리얼 구하기
	for (int i = 1;i <= n;i++)
	{
		fact[i] = i*fact[i - 1];
	}
	if (num == 1)
	{
		ll k = 0;
		scanf("%lld", &k);
		vector<int> v;
		for (int i = 0;i < n;i++)
		{
			//1-n까지 들어간 숫자 확인
			for (int j = 1;j <= n;j++)
			{
				//이미 있는 숫자 체크
				if (check[j]) continue;
				//k보다 작으면 그 수의 나머지 팩토릴얼 추가
				if (fact[n - i - 1] < k) k -= fact[n - i - 1];
				//k보다 크면
				else {

					check[j] = true;
					v.push_back(j);
					break; //그 자리수를 구했으므로 break;
				}
			}
		}
		for (auto x : v) printf("%d ", x);
		printf("\n");
	}
	else
	{
		vector<int> v;
		int tmp = 0;
		ll cnt = 0;
		for (int i = 0;i < n;i++)
		{
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		//각각 다른 자리수
		for (int i = 0;i < n;i++)
		{
			//입력받은 숫 찾는과정
			//같은 자리의 다른 숫자
			for (int j = 1;j < v[i];j++)
			{
				//이미 방문
				if (check[j]) continue;

				cnt += fact[n - i - 1];


			}
			//다 돌고 방문 표시
			check[v[i]] = true;
		}
		printf("%lld\n", cnt+1);
	}

	return 0;
}