#include<iostream>
#include<string>
#include<vector>
using namespace std;

string setting(int n);
int kmpsearch(string A, string B);
vector<int> getpartial(string B);

int main(void)
{
	string S, pat;
	int N, M;
	int ans;
	//N,M,S 입력받음1
	cin >> N;
	cin>> M;
	cin >> S;
	pat = setting(N);
	//cout << pat;
	ans = kmpsearch(S, pat);
	cout << ans << endl;

}

string setting(int n)
{
	string a = "I";
	for (int i = 0; i < n; i++){
		a+="OI";
	}
	return a;
}

int kmpsearch(string A, string B)
{
	int a = A.size();
	int b = B.size();

	vector<int> ans;
	vector<int> pi = getpartial(B);
	int count = 0;
	int begin = 0;
	int matched = 0;

	while (begin <= a - b){

		if (A[begin + matched] == B[matched]){
			++matched;
			if (matched == b){  //찾는 패턴의 끝까지 찾으면 
				ans.push_back(begin); //찾은 패턴의 문자열의 첫번쨰 위치를 저장
				count++;
			}
		}
		else{
			if (matched == 0)
				begin++; //아무것도 일치하지않으면 한개씩 증가
			else{
				begin += (matched-pi[matched - 1]);
				matched = pi[matched - 1];
			}
		}
	}

	return count;

	 
}


vector<int> getpartial(string pat)
{
	int a = pat.size();
	int begin = 1;  //왜냐하면 자신의 문자열을 자신이 찾는데 begin=0이면 완전히 일치하므로 begin =1부터 시작
	int matched = 0; // 크기 a이고 0으로 초기화
	vector<int> pi(a, 0);

	while (begin + matched < a){
		if (pat[begin + matched] == pat[matched]){
			++matched;
			pi[begin+matched-1] = matched;
		}
		else{
			if (matched == 0) ++begin;
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}


	}

	return pi;
}