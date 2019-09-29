#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> List;
	List.push_back(1);
	List.push_back(2);
	List.push_front(3);
	List.push_front(4);
	List.push_back(5);
	List.push_front(1);
	List.push_back(1);
	List.push_front(11);
	List.sort();
	//List.reverse();
	
	list<int>::iterator iter;
	for (iter = List.begin(); iter != List.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}