#include<vector>
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
vector<int> naivesearch(const string&H, const string &N);
vector<int> kmpsearch(const string&H, const string &N);
vector<int> getPartialMatch(const string &N);

int main(void)
{
	clock_t begin, end;
	string H;
	string N;
	cin >> H >> N;

	vector<int> answer;
	begin = clock();
	answer = kmpsearch(H, N);
	end = clock();
	for (size_t i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	printf("\"clocktime=%0.6f", (begin - end) / CLOCKS_PER_SEC);



}

vector<int> naivesearch(const string&H, const string&N)
{
	vector<int> ret;
	//모든 시작 위치를 다 시도해본다
	for (int begin = 0; begin + N.size() <= H.size(); begin++){
		bool matched = true;
		for (size_t i = 0; i < N.size(); ++i){
			if (H[begin + i] != N[i]){
				matched = false;
				break;
			}	
		}
		if (matched) ret.push_back(begin);
	}
	return ret;
}

vector<int> kmpsearch(const string &H, const string &N)
{
	//비교원본의 size 크기
	int n = H.size();

	//비교대상의 size 크기
	int m = N.size();

	//답을 저장하는 ret
	vector<int> ret;
	//접미사도 되고 접두사도 되는 문자열의 최대길이
	vector<int> pi = getPartialMatch(N);
	
	int begin = 0;
	int matched = 0; //일치한글자수

	while (begin <= n - m){
		//만약 같다면
		if (matched < m && H[begin + matched] == N[matched]){
			++matched;
			//결과적으로 m글자가 모두 일치했다면 답에 추가
			if (matched == m) ret.push_back(begin);
			
		}
		else
		{
			if (matched == 0) ++begin;
			else{
				begin += matched - pi[matched - 1];
				//begin을 옮겼다고 하더라도 처음부터 다시 비교할필요없다
				//옮긴 후에도 pi[matched-1]만큼은 항상 일치하기 때문이다
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}


//N에서 자기 자신을 찾으면서 나타나는 부분일치를 이용해 
//pi[]를 계산한다
//pi[..i]=N[,..i
vector<int> getPartialMatch(const string & N){
	int m = N.size();
	vector<int> pi(m, 0); //크기 m이고 0으로 초기화
	//KMP로 자기 자신을 찾는다
	//N에서 N을 찾는다. begin=0이면 자기 자신이므로 begin=1부터
	int begin = 1;
	int matched = 0;
	while (begin + matched < m){
		if (N[begin + matched] == N[matched]){
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else{
			if (matched == 0)
				++begin;//일치하는 글자가없으면 그 다음
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;

	
}