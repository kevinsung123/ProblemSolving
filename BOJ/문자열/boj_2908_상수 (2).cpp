#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	char A[3];
	char B[3];
	int a = 0;
	int b = 0;
	int c = 1;
	cin >> A >> B;

	for (int i = 0; i < 3; i++)
	{
		a += (A[i] - '0')*c;
		b += (B[i] - '0')*c;
		c *= 10;
	}

	cout<<( (a >b) ? a : b);

}