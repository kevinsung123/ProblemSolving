#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef pair<string, int> psi;

//<<연산자를 오버로딩 일반화
//template<typename a, typename b>
//ostream& operator<<(ostream& os, const pair<a, b>& pai) {
//	os << pai.first << ' ' << pai.second;
//	return os;
//}
//template<typename a, typename b>
//istream& operator>>(istream& is, pair<a, b>& pai) {
//	is >> pai.first >> pai.second;
//	return is;
//}
int main()
{
	//이름 사전순
	//이름이 같으면 나이순으로 정렬
	vector<psi> S;
	S.push_back({ "cc", 10 });
	S.push_back({ "ba", 24 });
	S.push_back({ "aa", 11 });
	S.push_back({ "cc", 8 });
	S.push_back({ "bb", 21 });
	cout << "오름차순" << "\n";
	sort(S.begin(), S.end(),less<psi>());
	for (auto i : S)
	{
		cout << i.first << ", " << i.second << "\n";
	}
	cout << "\n";
	cout << "내림차순" << "\n";
	sort(S.begin(), S.end(), greater<psi>());
	for (auto i : S)
	{
		cout << i.first << ", " << i.second << "\n";
	}
}
	
	