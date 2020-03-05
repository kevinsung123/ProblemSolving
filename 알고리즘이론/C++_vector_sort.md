### sort algorithm
- <algorithm>파일헤더에 존재
- sort(start, end) 를 이용하여 [start,end) 범위에있는인자를 오름차순 정렬
	- start는 포함, end는 미포함
- quick sort 기반으로 구현되어있어 시간 복잡도는 O(nlogn)
### 1. 원형 및 사용법
```
template <typename T>
1) void sort(T start, Tend)

2) void sort(T start, Tend,Compare comp)
```
- 3번째 인자 comp에따라 정렬 가능
```
sort(arr,arr+n);
sort(v.begin(), v.end());
sort(v.begin(), v.end(),compare); //사용자정의함수
sort(v.begin(), v.end(),greater<자료형>()); //내림차순
sort(v.begin(), v.end(),less<자료형>()); //오름차순

```
### 2. 예제
1. compare 함수를 만들어서 sort
```
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


```

2. vector와 pair를 활용환 서로다른 타입 이차원배열
```
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
	
	
```
