#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class S {
public:
	string name;
	int age;
	S(string name, int age) :name(name), age(age) {}
};

void P(vector<S> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].name<< ", " << v[i].age<< "\n";
	}
}

bool compare(S a, S b)
{
	if (a.name == b.name)
	{
		return a.age < b.age;
	}
	else return a.name < b.name;
}
int main()
{
	//이름 사전순
	//이름이 같으면 나이순으로 정렬
	vector<S> s;
	s.push_back(S("cc", 10 ));
	s.push_back(S("ba", 24));
	s.push_back(S("aa", 11));
	s.push_back(S("cc", 8));
	s.push_back(S("bb", 21));

	cout << "오름차순" << "\n";
	sort(s.begin(), s.end(), compare);
	P(s);
	cout << "\n";
	
}

