#include<vector>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
#define MAX 100

int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b%a, a);
}

int main(void)
{
	int N, d, i, g;
	cin >> N;
	vector<int> A(N);
	for (int i = 0;i < N;i++)
		cin >> A[i];
	sort(A.begin(), A.end());
	
	
	////입력받을 수들의 차 집합
	//vector<int> B;
	//for (i = 1;i < N;i++)
	//	B.push_back(A[i] - A[i - 1]);
	//sort(B.begin(), B.end());
	//B.erase(unique(B.begin(), B.end()), B.end());
	
	//차들의 집합의 최대공약수
	g = A[1] - A[0];
	for (i = 1;i < A.size()-1;i++)
		g = gcd(g, A[i+1] -A[i]);

	//최대공약수의 약수구하기
	vector<int> ans;
	for (i = 1;i*i <= g;i++)
	{
		if (g%i==0)
		{
			ans.push_back(i);
			if (g / i != i) ans.push_back(g / i);
		}
	}
	sort(ans.begin(), ans.end());
	for (i = 0;i < ans.size();i++)
		if (ans[i] != 1) cout << ans[i] << " ";

	/*for (int i = 0;i < A.size();i++)
		cout << A[i] << " ";*/

}