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

	//greater-than ����(/min-heap ���ǽ� ���)
	// operator > ���� True�̸� swap False�̸� �Ѿ
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
	�Լ�
	empty
	push
	top
	pop
	*/

	/*max-heap ���� �������� less �Լ� ���*/
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

	/* min-heap ���� �������� greater �Լ� ��� */
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




