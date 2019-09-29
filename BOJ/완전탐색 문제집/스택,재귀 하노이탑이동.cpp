#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int n;
stack <int>s;


int Stack[10];
int cur;

//***** Stack 이용을 위한 함수 *****//
void InitStack()
{
	cur = -1;
}

void Push(int data)
{
	if (cur >= 10 - 1)
	{
		printf("Stack overflow!!!\n");
		return;
	}

	Stack[++cur] = data;
}

int Pop()
{
	if (cur < 0)
	{
		printf("Stack is already empty!!!\n");
		return 0;
	}

	return Stack[cur--];
}

int IsEmpty()
{
	if (cur < 0)
		return 1;
	else
		return 0;
}


void Print(int n, int from, int to)
{
	printf("원반%d를 %c에서 %c로 이동\n", n, from, to);
}






// 하노이 타워 반복문 구현 함수(스택 이용)
void Hanoi(int n, int from, int by, int to)
{
	int bContinue = 1;
	InitStack();

	while (bContinue)
	{
		while (n > 1)
		{
			Push(to);
			Push(by);
			Push(from);
			Push(n);
			--n;
			Push(to);
			to = by;
			by = Pop();
		}
		Print(n, from, to);
		if (!IsEmpty())
		{
			n = Pop();
			from = Pop();
			by = Pop();
			to = Pop();
			Print(n, from, to);
			--n;
			Push(from);
			from = by;
			by = Pop();
		}
		else
			bContinue = 0;
	}
}





void HanoiTowerMove(int num, char from, char by, char to)
{
	printf("num=%d fromt=%c by=%c to=%c\n", num, from, by, to);
	if (num == 1) {
		printf("원반1을 %c에서 %c로 이동\n", from, to);
	}
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반%d를 %c에서 %c로 이동\n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}

}
int main(int arc, char** argv)
{
	printf("하노이 타워 재귀 구현\n");
	HanoiTowerMove(3, 'A', 'B', 'C');
	printf("\n");
	printf("하노이 타워 반복문 구현\n");
	Hanoi(3, 'A', 'B', 'C');
	return 0;
}
