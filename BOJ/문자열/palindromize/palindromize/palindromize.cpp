#include<algorithm>
#include<cassert>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> getpartialmatch(string s);
int maxoverlap(string s, string b);

int main(void)
{
	cin.sync_with_stdio(false);
	int C;
	cin >> C;
	string input;
	string rev;
	

	


	for (int i = 0; i < C; i++)
	{
		cin >> input;
		rev = input;
		reverse(rev.begin(), rev.end());

		cout << 2*input.size() - maxoverlap(input, rev) << endl;
	}
}

vector<int> getpartialmatch(string s)
{
	int k = s.size();
	vector<int> pi(k, 0);
	int begin = 1, matched = 0;

	while (begin + matched < k){
		if (s[begin + matched] == s[matched]){
			++matched;
			pi[begin + matched - 1] = matched;

		}
		else{
			if (matched == 0)
				++begin;
			else{
				begin += matched - pi[matched - 1];
			}
		}
	}
	return pi;
}

int maxoverlap(string a,string b)
{
	int m = a.size();
	int n = b.size();

	vector<int> pi = getpartialmatch(b);

	int begin = 0, matched = 0;
	while (begin <= m-n)
	{
		if (matched<n && a[begin + matched] == b[matched]){
			++matched;
			if (begin+matched == n)
				return matched;
		}
		else{
			if (matched == 0)
				++begin;
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}


	}
	return 0;
}