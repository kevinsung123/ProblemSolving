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




