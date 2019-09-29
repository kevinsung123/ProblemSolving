#include <iostream>
#include <cstdlib>
using namespace std;

class InvalidIndexException {};

template<typename T>
class ListNode {
public:
	T value;
	ListNode<T> * next;  

	//생성자
	ListNode<T>() : next(nullptr) {}
	ListNode<T>(T value, ListNode<T> * next) : value(value), next(next) {}
};

template<typename T>
class LinkedList {
public:
	int size;
	ListNode<T> * head;

	//생성자
	LinkedList<T>() : size(0), head(nullptr) {}

	//소멸자 
	~LinkedList<T>() {
		ListNode<T> *t1 = head, *t2;
		while (t1 != nullptr)
		{
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}

	//멤버함수
	void insert(int k, T value)
	{
		try 
		{
			//예외처리 : 잘못된 인덱스
			if (k<0 || k>size) throw InvalidIndexException();

			//처음 삽입
			if (k == 0)
			{
				head = new ListNode<T>(value, head);
			}
			//K번째 원소 삽입
			else
			{
				ListNode<T> *dest = head;
				for (int i = 0; i < k - 1; i++) dest = dest->next;
				dest->next = new ListNode<T>(value, dest->next); //새로운 노드값 넣고, 그 다음을 가리키게함
			}

			size++;
		}
		catch (InvalidIndexException e)
		{
			cerr << "잘못된 인덱스입니다 " << endl;
			exit(1);
		}
	}

	//k번째 원소를 제거 
	void erase(int k)
	{
		try
		{
			if (k < 0 || k >= size) throw InvalidIndexException();

			if (k == 0)
			{
				ListNode<T> *tmp = head->next;
				delete head;
				head = tmp;
			}
			else
			{
				ListNode<T> *dest = head, *tmp;
				for (int i = 0; i < k - 1; i++) dest = dest->next;
				tmp = dest->next->next;
				delete dest->next;
				dest->next = tmp;
			}

			size--;
		}
		catch (InvalidIndexException e)
		{
			cerr << "잘못된 인덱스 이빈다" << endl;
			exit(2);
		}
	}

	//순회 메서드
	int search(T value)
	{
		ListNode<T> *tmp = head;
		for (int i = 0; i < size; i++)
		{
			if (tmp->value == value) return i;
			tmp = tmp->next;
		}
		return -1; //못 찾을경우
	}

};


template<typename T>
ostream& operator <<(ostream &out, const LinkedList<T> &LL)
{
	ListNode<T> * tmp = LL.head;
	out << '[';
	for (int i = 0; i < LL.size; i++)
	{
		out << tmp->value;
		tmp = tmp->next;
		if (i < LL.size - 1) out << ",";
	}
	cout << ']';
	return out;
}

int main() {
	LinkedList<int> LL;
	LL.insert(0, 1); cout << LL << endl;
	LL.insert(1, 2); cout << LL << endl;
	LL.insert(2, 3); cout << LL << endl;
	LL.insert(0, 4); cout << LL << endl;
	LL.insert(0, 5); cout << LL << endl;
	LL.insert(5, 6); cout << LL << endl;
	LL.insert(4, 7); cout << LL << endl;
	LL.insert(1, 8); cout << LL << endl;
	LL.erase(4); cout << LL << endl;
	LL.erase(0); cout << LL << endl;
	LL.erase(5); cout << LL << endl;
	LL.insert(3, 9); cout << LL << endl;
	LL.erase(1); cout << LL << endl;
	LL.insert(1, 10); cout << LL << endl;
	cout << "end" << endl;

}


