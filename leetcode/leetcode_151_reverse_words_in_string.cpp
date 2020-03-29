#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



class Solution {
public:
	string reverseWords(string s) {

		vector<string> ans;

		////입력받은 문자열을 parsing
		int idx = 0;
		while(idx<s.length())
		{
			string tmp = "";
			//whitespace이면 continue 및 idx 증가
			if (s[idx] == ' ') idx++;
			//whitespace이면아니면 separator=구분자로 두고 단어를 저장
			else {
				
				//만약 whitespace이면 다른단어
				while (s[idx] != ' ' and idx < s.length())
				{
					tmp += s[idx];
					idx++;
				}
				ans.push_back(tmp);
			}
		
			
		}
		reverse(ans.begin(), ans.end());
		string ret = "";
		for (int i=0;i<ans.size();i++)
		{
			ret += ans[i];
			if(i<ans.size()-1)ret += " ";
				
		}


		return ret;
	}
};


int main()
{
	ios::sync_with_stdio(false);

	string s;
	getline(cin,s);
	cout << "입력값: " << s << "\n";

	Solution sol= Solution();
	sol.reverseWords(s);
	

}