#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	string str;
	string rev;

	cin >> str;
	rev = str;
	reverse(rev.begin(), rev.end());

	if (str == rev) cout << 1 << endl;
	else cout << 0;


}