#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int cache[10][10];

int gcd(int a, int b) //유클리드호제법
{
	return b == 0 ? a : gcd(b, a%b);
}

//분수 a/b보다 같거나 큰 최소의 자연수를 반환한다
int ceil(int a, int b)
{
	return ( a + b -1 ) / b;
}

//마법의 약 레시피와 이미 넣은 재료의 양이 주어질떄, 더 넣을 재료의 양을 구한다
vector<int> solve( vector<int> & recipe,  vector<int>& put)
{
	int n = recipe.size();
	//모든 recipe[]의 최대공약수를 구한다
	int b = recipe[0];

	//2개 이상의 최대공약수를 구하는 방법 
	for (int i = 1; i < n; i++) b = gcd(b, recipe[i]);

	//최소한 b/b=1배는 만들어야 하므로,  a의 초기값을 b로 둔다.
	int a = b;
	
	//X를 직접 구하는 대신에 ceil[put[i]*b,recipe[i])의 최대값을 구한다
	for (int i = 0; i < n; i++)
		a = max(a, ceil(put[i] * b, recipe[i]));

	//a/b배 분량을 만들면 된다
	vector<int> ret(n);

	for (int i = 0; i < n; i++)
		ret[i] = recipe[i] * a / b - put[i];
	return ret;
}

int main(void)
{
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < 10;i++)
	for (int j = 0; j < 10; j++)
		cout << cache[i][j] << " ";
	cout << endl;
	
	ios::sync_with_stdio(false);
	int c, n, r, p;
	//cin >> c;
	//while (c--)
	//{
	//	vector<int> ans;
	//	vector<int> recipe;
	//	vector<int> put;
	//	cin >> n; //첫줄에 재료의수 입력 받음
	//	for (int i = 0; i < n; i++)
	//	{
	//		cin >> r;
	//		recipe.push_back(r);
	//	}
	//	
	//	for (int i = 0; i < n; i++)   //이미 냄비에 넣은 재료의양
	//	{
	//		cin >> p;
	//		put.push_back(p);
	//	}
	//	ans=solve(recipe, put);


	//	for (size_t i = 0; i < ans.size(); i++)
	//		cout << ans[i] << " ";
	//}

}