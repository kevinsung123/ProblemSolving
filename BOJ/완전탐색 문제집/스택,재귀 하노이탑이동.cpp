#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int n;
stack <int>s;


int Stack[10];
int cur;

//***** Stack �̿��� ���� �Լ� *****//
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
	printf("����%d�� %c���� %c�� �̵�\n", n, from, to);
}






// �ϳ��� Ÿ�� �ݺ��� ���� �Լ�(���� �̿�)
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
		printf("����1�� %c���� %c�� �̵�\n", from, to);
	}
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("����%d�� %c���� %c�� �̵�\n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}

}
int main(int arc, char** argv)
{
	printf("�ϳ��� Ÿ�� ��� ����\n");
	HanoiTowerMove(3, 'A', 'B', 'C');
	printf("\n");
	printf("�ϳ��� Ÿ�� �ݺ��� ����\n");
	Hanoi(3, 'A', 'B', 'C');
	return 0;
}
