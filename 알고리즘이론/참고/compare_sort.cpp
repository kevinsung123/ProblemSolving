#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef pair<string, int> psi;

//<<�����ڸ� �����ε� �Ϲ�ȭ
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
	//�̸� ������
	//�̸��� ������ ���̼����� ����
	vector<psi> S;
	S.push_back({ "cc", 10 });
	S.push_back({ "ba", 24 });
	S.push_back({ "aa", 11 });
	S.push_back({ "cc", 8 });
	S.push_back({ "bb", 21 });
	cout << "��������" << "\n";
	sort(S.begin(), S.end(),less<psi>());
	for (auto i : S)
	{
		cout << i.first << ", " << i.second << "\n";
	}
	cout << "\n";
	cout << "��������" << "\n";
	sort(S.begin(), S.end(), greater<psi>());
	for (auto i : S)
	{
		cout << i.first << ", " << i.second << "\n";
	}
}
	
	