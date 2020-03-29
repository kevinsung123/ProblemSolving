#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



class Solution {
public:
	string reverseWords(string s) {

		vector<string> ans;

		////�Է¹��� ���ڿ��� parsing
		int idx = 0;
		while(idx<s.length())
		{
			string tmp = "";
			//whitespace�̸� continue �� idx ����
			if (s[idx] == ' ') idx++;
			//whitespace�̸�ƴϸ� separator=�����ڷ� �ΰ� �ܾ ����
			else {
				
				//���� whitespace�̸� �ٸ��ܾ�
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
	cout << "�Է°�: " << s << "\n";

	Solution sol= Solution();
	sol.reverseWords(s);
	

}