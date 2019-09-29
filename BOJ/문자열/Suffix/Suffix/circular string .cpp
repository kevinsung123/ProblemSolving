#include<vector>
#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;


vector <int> getsuffixarray(const string &s);
string minshift(string s); //���̻� �迭�� �̿��� ���� ���ڿ� ���� �ذ� 

//���ڿ����̰� n�ϋ�, [0..n-1]������ ������ ��� ���� �����迭�� �����ϵ�, 
//�� ������ ���Ҷ� �ش� ��ġ���� ���� �ϴ� ���̻���� ��
//C++ STL�� sort�Լ��� ���ϵ� ������ ���ڸ� ����
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

	//������ overloading
	bool operator()(int a, int b){
		//ù t���ڰ� �ٸ��� �̵��� �̿��� ���Ѵ�.
		if (group[a] != group[b]) return group[a] < group[b];
		//�׷��� ������ S[a+t..]�� S[b+t..]�� ù t���ڸ� �� ��, ������ 2t���ڸ� �� 
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
	sort(perm.begin(), perm.end(), SuffixComparator(s)); //������������ ����
	return perm;
}

vector<int> getSuffixArray(string s){
	int n = s.size();
	//group[i]=���̻���� ù t���ڸ� �������� ����������, S[i..]�� ���� ��ȣ
	//t=1�϶��� �����Ұ� ���� S[i..]�� ù���ڷ� �׷��ȣ�� �����൵ ���� ȿ�� 
	int t = 1;

	vector<int> group(n + 1);
	for (int i = 0; i < n; i++) group[i] = s[i];
	group[n] = -1; //ũ�Ⱑ n+1�̹Ƿ� 0,1,2,3,,,,n (n+1��)
	//��������� ���̻�迭�� �� perm. �� �迭�� lgN�� �����Ѵ�
	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;
	while (t < n){
		//group[]�� ù t����(t=1)�������� ����ص״�
		//ù 2t���ڸ� �������� perm�� �ٽ� �����Ѵ�
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		t *= 2;
		if (t >= n) break;

		//2t���ڸ� �������� �� �׷� ������ �����
		vector<int> newgroup(n + 1);
		newgroup[n] = -1;
		newgroup[perm[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			if (compareUsing2T(perm[i - 1], perm[i])) //T��� perm[i-1] < perm[i] �̴� 
				newgroup[perm[i]] = newgroup[perm[i - 1]] + 1; //���� �׷��� ��ȣ +1
			else
				newgroup[perm[i]] = newgroup[perm[i - 1]]; //F��� �����Ƿ� ���� ���̻�� ù2t���ڰ� �����ϱ� ���� �׷��ȣ�� �ο�
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