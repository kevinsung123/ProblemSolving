#include<vector>
#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;


vector <int> getsuffixarray(const string &s);
string minshift(string s); //접미사 배열을 이용해 원형 문자열 문제 해결 

//문자열길이가 n일떄, [0..n-1]범위의 정수를 모두 담은 정수배열을 정렬하되, 
//두 정수를 비교할때 해당 위치에서 시작 하는 접미사들을 비교
//C++ STL의 sort함수로 비교하되 별도의 비교자를 구현
struct SuffixComparator{
	const string & s;
	SuffixComparator(const string & s) : s(s) {}
	bool operator()(int i, int j){
		return strcmp(s.c_str() + i, s.c_str() + j) < 0;
	}
};

struct Comparator{
	vector<int> group;
	int t;
	Comparator(vector <int> group_, int _t) : group(group_), t(_t) { group = group_; t = _t; }

	//연산자 overloading
	bool operator()(int a, int b){
		//첫 t글자가 다르면 이들을 이용해 비교한다.
		if (group[a] != group[b]) return group[a] < group[b];
		//그렇지 않으면 S[a+t..]와 S[b+t..]의 첫 t글자를 비교 즉, 이전의 2t글자를 비교 
		return group[a + t] < group[b + t];
	}
};


int main(void)
{

	/*string s = "bcetfgc";
	size_t n = s.size();
	vector<int> group(n+1);
	for (size_t i = 0; i < n; i++) group[i] = s[i];
	group[n] = -1;
	for (size_t i = 0; i < n+1; i++) cout << group[i] << " ";*/

	string s;
	cin >> s;
	cout << "s=" << s << endl;
	string ans = minshift(s);
	cout << ans;
}

vector<int> getsuffixarray(const string & s)
{
	vector<int> perm;
	for (size_t i = 0; i < s.size(); i++) perm.push_back(i);
	sort(perm.begin(), perm.end(), SuffixComparator(s)); //오름차순으로 정렬
	return perm;
}

vector<int> getSuffixArray(string s){
	int n = s.size();
	//group[i]=접미사들을 첫 t글자를 기준으로 정렬했을때, S[i..]가 들어가는 번호
	//t=1일때는 정렬할것 없이 S[i..]의 첫글자로 그룹번호를 정해줘도 같으 효과 
	int t = 1;

	vector<int> group(n + 1);
	for (int i = 0; i < n; i++) group[i] = s[i];
	group[n] = -1; //크기가 n+1이므로 0,1,2,3,,,,n (n+1개)
	//결과적으로 접미사배열이 될 perm. 이 배열을 lgN번 정렬한다
	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;
	while (t < n){
		//group[]은 첫 t글자(t=1)기준으로 계산해뒀다
		//첫 2t글자를 기준으로 perm을 다시 정렬한다
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		t *= 2;
		if (t >= n) break;

		//2t글자를 기준으로 한 그룹 정보를 만든다
		vector<int> newgroup(n + 1);
		newgroup[n] = -1;
		newgroup[perm[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			if (compareUsing2T(perm[i - 1], perm[i])) //T라면 perm[i-1] < perm[i] 이다 
				newgroup[perm[i]] = newgroup[perm[i - 1]] + 1; //이전 그룹의 번호 +1
			else
				newgroup[perm[i]] = newgroup[perm[i - 1]]; //F라면 같으므로 이전 접미사와 첫2t글자가 같으니까 같으 그룹번호를 부여
		}
		group = newgroup;
		
	}
	return perm;
}

string minshift(string s)
{
	string s2 = s + s;
	vector<int> a = getSuffixArray(s2);

	for (size_t i = 0; i < a.size(); ++i){
		if (a[i] <= s.size())
			return s2.substr(a[i], s.size());
	}

	return "no answer";
}