#include <iostream>
#include <cstdlib>
using namespace std;

class InvalidIndexException {};

template<typename T>
class ListNode {
public:
	T value;
	ListNode<T> * next;  

	//������
	ListNode<T>() : next(nullptr) {}
	ListNode<T>(T value, ListNode<T> * next) : value(value), next(next) {}
};

template<typename T>
class LinkedList {
public:
	int size;
	ListNode<T> * head;

	//������
	LinkedList<T>() : size(0), head(nullptr) {}

	//�Ҹ��� 
	~LinkedList<T>() {
		ListNode<T> *t1 = head, *t2;
		while (t1 != nullptr)
		{
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}

	//����Լ�
	void insert(int k, T value)
	{
		try 
		{
			//����ó�� : �߸��� �ε���
			if (k<0 || k>size) throw InvalidIndexException();

			//ó�� ����
			if (k == 0)
			{
				head = new ListNode<T>(value, head);
			}
			//K��° ���� ����
			else
			{
				ListNode<T> *dest = head;
				for (int i = 0; i < k - 1; i++) dest = dest->next;
				dest->next = new ListNode<T>(value, dest->next); //���ο� ��尪 �ְ�, �� ������ ����Ű����
			}

			size++;
		}
		catch (InvalidIndexException e)
		{
			cerr << "�߸��� �ε����Դϴ� " << endl;
			exit(1);
		}
	}

	//k��° ���Ҹ� ���� 
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
			cerr << "�߸��� �ε��� �̺��" << endl;
			exit(2);
		}
	}

	//��ȸ �޼���
	int search(T value)
	{
		ListNode<T> *tmp = head;
		for (int i = 0; i < size; i++)
		{
			if (tmp->value == value) return i;
			tmp = tmp->next;
		}
		return -1; //�� ã�����
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


