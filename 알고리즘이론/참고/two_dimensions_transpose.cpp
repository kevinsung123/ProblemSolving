#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<functional>
using namespace std;
#define SIZE 5

static int b[5][5];
static int B[5][5];



void clear()
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++) b[y][x] = 0;
	}
}

void P(int (*a)[5])
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
			cout << a[y][x] << " ";
		cout << "\n";
	}
}

int  (*Transpose(int a[][5]) )[5]
{
	//static을 붙이는 이유는 지역할당이기때문에 날아감
	//clear();
	int tmp[5][5] = {0};
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			tmp[y][x] = a[x][y];

		}
	}

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
			b[y][x] = tmp[y][x];
	}

	return b;
}

int main()
{
	int M[5][5];
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
			M[y][x] = (y*5)+(x + 1);
	}

	P(M);
	cout << "\n\n";
	int(*c)[5] = Transpose(M);
	P(c);
	int(*d)[5] = Transpose(c);
	int X[5][5];
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
			X[y][x] = d[y][x];
	}
	cout << "\n\n";
	P(X);
	
}