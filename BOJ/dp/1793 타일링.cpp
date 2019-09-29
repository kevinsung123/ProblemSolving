#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
string d[251]={ "1","1" };


string f(string a, string b)
{
	string res;
	int sum = 0;
	while (!a.empty() || !b.empty() || sum)
	{
		if (!a.empty()) sum += a.back() - '0',a.pop_back();
		if (!b.empty()) sum += b.back() - '0',b.pop_back();
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}

	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	int n = 0;
	for (int i = 2;i <= 250;i++) d[i] = f(f(d[i - 2], d[i - 2]), d[i - 1]);
	while (cin>>n)
	{
		cout << d[n] << "\n";
	}
}