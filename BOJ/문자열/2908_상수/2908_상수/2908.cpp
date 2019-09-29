#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
void sum(int *A, int * B);
int a[3];
int b[3];


int main(void)
{
	int A, B;
	int new_A = 0;
	int new_B = 0;
	scanf("%3d %3d", &A, &B);

	//A,B 각각의 수를 배열에 저장
	for (int i = 0; i < 3; i++){
		a[i] = A%10;
		A /= 10;
		b[i] = B%10;
		B /= 10;
	}
	
	
	//배열에 저장된 수를 다시 합침
	int sum_a = 0;
	int sum_b = 0;


	sum_a = a[0] * 100 + a[1] * 10 + a[2];
	sum_b = b[0] * 100 + b[1] * 10 + b[2];

	
	if (sum_a > sum_b) printf("%d\n", sum_a);
	else printf("%d\n", sum_b);

	
}

