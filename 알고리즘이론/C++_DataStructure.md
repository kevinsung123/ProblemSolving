## 힙(heap)이란
- 완전 이진 트리의 일종으로 우선순위큐를 이용한 자료구조
- 여러개 값들 중에서 최댓값이나 최솟값을 빠르게 찾아내도록 만들어진 자료구조
-  힙은 일종의 반정렬상태를 유지
	- 큰값이 상위 레벨에 있고 작은값이 하위레벨에 존재
	- 부모노드의 키 값이 자식 노드의 키값보다 항상 큰(작은) 이진트리
	- 중복된값을 허용
## 힙종류
- 최대힙(max heap)
	- key(부모노드) >= key(자식노드)
- 최소힙(min heap)
	- key(부모노드)<= key(자식노드)
![enter image description here](https://gmlwjd9405.github.io/images/data-structure-heap/types-of-heap.png)
## 힙구현
- 힙의 기본 표준 자료구조는 배열
- 배열의 첫번쨰 인덱스0 사용 x
- 특정 위치의 노듭너호는 새로운 노드가 추가되어도 변형 x
	- ex) 루트노드의 오른쪽노드번호는 항상  3
- 힙에서 부도/자식 노드 관계
	- 왼쪽자식 인덱스 = (부모의인덱스)*2
	- 오른쪽자식 인덱스 = (부모의인덱스)*2+1
	![enter image description here](https://gmlwjd9405.github.io/images/data-structure-heap/heap-index-parent-child.png)
##  우선순위큐를 이용한 max/min-heap
- priorty_queue
	- priority_queue<자료형,구현체,비교연산자>
	```
	■ 자료형 : int, doucle,선언한 클래스 etc
	■ 구현체 : 기본적으로 vecotr<자료형>, 실제로 vector위에서 작동
	 vector, deque를 include 하지 않더라도 잘돌아감
	■ 비교연산자 
		 - 기본적으로 less<자료형> = 비교연산자 클래스 내림차순 ex) 54321
		 - greater<자료형> = 오름차순 ex)113459
	```

- less : 첫번째 인자가 두번째 인자보다 작으면 true 반환 (bool) 
	```
	<C++11>
	template <class T> struct less {
	  bool operator() (const T& x, const T& y) const {return x<y;}
	  typedef T first_argument_type;
	  typedef T second_argument_type;
	  typedef bool result_type;
	};
   <example>
	less
	#include <iostream>     // std::cout
	#include <functional>   // std::less
	#include <algorithm>    // std::sort, std::includes

	int main () {
	  int foo[]={10,20,5,15,25};
	  int bar[]={15,10,20};
	  std::sort (foo, foo+5, std::less<int>());  // 5 10 15 20 25
	  std::sort (bar, bar+3, std::less<int>());  //   10 15 20
	  if (std::includes (foo, foo+5, bar, bar+3, std::less<int>()))
	    std::cout << "foo includes bar.\n";
	  return 0;
	}
	```
- greater : 첫번째 인자가 두번째인자보다 크면 true 반환	
	 ```
	 <C++11>
	template <class T> struct greater {
	  bool operator() (const T& x, const T& y) const {return x>y;}
	  typedef T first_argument_type;
	  typedef T second_argument_type;
	  typedef bool result_type;
	};
	 <example>
	// greater example
	#include <iostream>     // std::cout
	#include <functional>   // std::greater
	#include <algorithm>    // std::sort

	int main () {
	  int numbers[]={20,40,50,10,30};
	  std::sort (numbers, numbers+5, std::greater<int>());
	  for (int i=0; i<5; i++)
	    std::cout << numbers[i] << ' ';
	  std::cout << '\n';
	  return 0;
	}
  ```
  
  ### 예제1
  ```
	#include<iostream>
	#include<vector>
	#include<algorithm>
	#include<queue>
	#include<functional>
	using namespace std;

	class minheap {
	public:

		minheap(int y, int x,int c) : _y(y), _x(x),_c(c) {}

		void print() { cout << "minheap : " << _y << "," << _x <<" ="<<_c<< "\n"; }

		//greater-than 정의(/min-heap 정의시 사용)
		// operator > 값의 True이면 swap False이면 넘어감
		bool operator >(const minheap &a) const
		{
				return _c > a._c;
		}


	private:
		int _y, _x, _c;

	};

	int main()
	{
		/*
		함수
		empty
		push
		top
		pop
		*/

		/*max-heap 구현 내림차순 less 함수 사용*/
		priority_queue<int> max_heap;  //max-heap less 


		max_heap.push(8);
		max_heap.push(1);
		max_heap.push(6);
		max_heap.push(2);
		max_heap.push(4);

		while (!max_heap.empty())
		{
			cout << max_heap.top() << "\n";
			max_heap.pop();
		}
		/* min-heap 구현 오름차순 greater 함수 사용 */
		priority_queue<minheap, vector<minheap>, greater<minheap>> q;
		q.push(minheap(1, 3, 4));
		q.push(minheap(2, 5, 1));
		q.push(minheap(7, 1, 7));
		q.push(minheap(3, 4, 2));
		q.push(minheap(5, 2, 9));

		while (!q.empty())
		{
			minheap tmp = q.top();
			tmp.print();
			q.pop();
		}
	}
	 ```
###  예제2
  ```
	 #include <cstdio>
	#include <queue>
	using namespace std;
	struct a{
	int start;
	int end;
	int value;
	};
	bool operator<(a t, a u){
	return t.value < u.value;
	}
	priority_queue<a> pq;
 ```
