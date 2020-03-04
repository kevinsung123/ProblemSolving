#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> getpartialmatch(string s);
vector<int> getprefixsuffix(string s);

int main(void)
{
	string A,B;
	cin >> A >> B;
	
	vector<int> ans = getprefixsuffix(A + B);
	sort(ans.begin(), ans.end());

	int k = ans.size();
	for (size_t i = 0; i < k; i++)
		cout << ans[i] << " ";


}


vector<int> getpartialmatch(string s)
{
	int size = s.size();
	vector<int> pi(size, 0);

	int begin = 1, matched = 0;

	while (begin + matched < size){

		if (s[begin + matched] == s[matched]){
			++matched;  
			pi[begin + matched - 1] = matched;
		}
		else{
			if (matched == 0)
				begin++;
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> getprefixsuffix(string s)
{
	int size = s.size();
	vector<int> ans;
	vector<int> pi = getpartialmatch(s);

	while (size > 0){
		ans.push_back(size);
		size = pi[size - 1];
	}
	return ans;
}