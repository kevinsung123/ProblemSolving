## 맵 기본 함수

#### 기본형태

-   `map<key,value>`  : key와 value를 pair 형태로 선언합니다.

#### iterator(반복자)

-   `begin()`  : beginning iterator를 반환
-   `end()`  : end iterator를 반환

#### 추가 및 삭제

-   `insert( make_pair(key,value) )`  : 맵에 원소를  `pair`  형태로 추가
-   `erase(key)`  : 맵에서 key(키값)에 해당하는 원소 삭제
-   `clear()`  : 맵의 원소들 모두 삭제

#### 조회

-   `find(key)`  : key(키값)에 해당하는 iterator를 반환
-   `count(key)`  : key(키값)에 해당하는 원소들(value들)의 개수를 반환

#### 기타

-   `empty()`  : 맵이 비어있으면 true 아니면 false를 반환
-   `size()`  : 맵 원소들의 수를 반환

## map 클래스

>map클래스는 이진 검색 트리 기반의 자료 구조이다. 일반적인 이진 검색 트리는 한 방향으로 쏠린 형태로 만들어져 효율성이 떨어질 수 있는데 map은 레드 트리 구조로 되어 있어서 항상 일정한 효율성을 보장한다. 레드 트리 구조는 직접 구현하기 매우 복잡해서 C++의 표준 라이브러리 중 하나인 map클래스를 사용하는 것이 좋다.
 #### set과의 비교
> set클래스 역시 map과 같이 효율적인 이진 탐색을 보장하는 자료 구조이다. 차이점은 map의 경우 key와 value가 존재하며 그 자료형도 자유롭게 지정할 수 있다. set은 한 가지 자료형으로된 key만으로 구성된 컨테이너이다. set의 원래 의미인 집합을 생각해 보면 한 가지 자료형으로 구성된 컨테이너라는 의미가 느껴진다.

### map의 선언

> map을 선언할 때는 key에 해당하는 자료형과 value에 해당하는 자료형을 함께 선언해준다.

```null
map<char,int> m;
m['A'] = 2;
m.insert(make_pair('A',2));
```

> char형의 key값과 int형의 value값을 가진 map을 선언한 모습이다. 값을 넣을 때는 key값을 인덱스로 value를 할당해 줘도 되고 make_pair함수를 이용해 pair형 자료를 삽입해 주어도된다.

## upper_bound, lower_bound 메서드

> map과 set클래스는 upper_bound와 lower_bound라는 메서드를 가지고 있다. 두 함수는 반대되는 개념일것 같지만 거의 유사한 기능을 한다.  
> upper_bound함수의 경우 컨테이너의 오른쪽 원소 중 기준 원소보다 큰 값중 가장 왼쪽에 있는 원소의 iterator값을 리턴한다.  
> lower_bound함수의 경우 오른쪽 원소 중 기준 원소와 같거나 큰 값 중 가장 왼쪽에 있는 원소의 iterator값을 리턴한다.  
> 차이점은 같은 값을 포함하느냐 마느냐의 차이만 있다.

```null
  mymap['a']=20;
  mymap['b']=40;
```

mymap['c']=60;  
mymap['d']=80;  
mymap['e']=100;

itlow=mymap.lower_bound ('b');  
itup=mymap.upper_bound ('d');

> 위 코드의 경우 itlow는 b를 itup은 e를 가르키는 iterator가 된다.
```
```
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

	// map
	// <string, int> => <key, value>
	map< string, int > m;


	// insert(key,value)
	m.insert(make_pair("a", 1));
	m.insert(make_pair("b", 2));
	m.insert(make_pair("c", 3));
	m.insert(make_pair("d", 4));
	m.insert(make_pair("e", 5));
	m["f"] = 6; // also possible


	// erase(key)
	m.erase("d");
	m.erase("e");
	m.erase(m.find("f")); // also possible


	// empty(), size()
	if(!m.empty()) cout << "m size : " << m.size() << '\n';


	// find(key)
	cout << "a : " << m.find("a")->second << '\n';
	cout << "b : " << m.find("b")->second << '\n';


	// count(key)
	cout << "a count : " << m.count("a") << '\n';
	cout << "b count : " << m.count("b") << '\n';


	// begin(), end()
	cout << "traverse" << '\n';
    // map< string, int >::iterator it; also possible 
	for(auto it = m.begin(); it != m.end(); it++){
		cout << "key : " << it->first << " " << "value : " << it->second << '\n';
	}

	return 0;

}
```
```
