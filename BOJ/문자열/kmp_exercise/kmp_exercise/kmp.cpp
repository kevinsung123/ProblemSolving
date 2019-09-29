#include<vector>
#include<iostream>
#include<string>
using namespace std;

vector<int> naivesearch(string &H, string &N);
vector<int> kmpsearch(string &H, string &N);
vector<int> partialmatch(string &N);


int main(void)
{
	string a, b;
	cin >> a >> b;
	
	vector<int> answer;

	answer = kmpsearch(a, b);

	for (size_t i = 0; i < answer.size(); i++)
		printf("%s%d", (i ? "," : ""), answer[i]);
		/*cout << answer[i] << " ";*/



}

vector<int> naivesearch(string &H, string &N){
	vector<int> ret;
	int h = H.size();
	int n = N.size();

	for (int begin = 0; begin + n <= h; begin++){
		bool matched = true;
		for (int i = 0; i < n; i++){
			if (H[begin + i] != N[i]){
				matched = false;
				break;  //만약 mismatch하면 for문을 벗어남

			}
		}
		if (matched) ret.push_back(begin);//일치하면 그 위치를 vector에 삽입

		return ret;
	}
}
		


vector<int> kmpsearch(string &H, string &N)
{
	vector<int> ret; //return 받을 vector 값
	int h = H.size();
	int n = N.size();

	int begin = 0;  //시작 위치
	int matched = 0; //match한 글자수
	vector<int> pi = partialmatch(N);

	while (begin <= h - n){
		//만약 같다면
		if (matched < n && H[begin + matched] == N[matched]){
			++matched; //일치한다면 matched 한개씩 증가
			if (matched == n) ret.push_back(begin);  //모두 같다면 그 시작위치를 push_back
		}
		else{
			if (matched == 0) begin++; //match한 글자가 아무것도 없으면 시작위치1 증가
			else
			{
				begin += matched - pi[matched - 1];  //부분배열을 이용하여 시작위치 증가
				matched = pi[matched - 1];
			}
		}

	}
	return ret;

	
}

vector<int> partialmatch(string &N)
{
	int n = N.size();
	vector<int> pi(n, 0);

	//N에서 자기자신을 match한다. 자기자신과 같으면 안되므로 begin!=0
	int begin = 1;
	int matched = 0;

	while (begin + matched < n){
		if (N[begin + matched] == N[matched]){
			++matched;
			pi[begin + matched - 1] = matched;
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