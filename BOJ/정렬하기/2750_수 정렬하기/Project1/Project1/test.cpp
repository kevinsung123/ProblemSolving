#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;


void selectionsort(int * A, int n)
{
	//n-2 passes  sorted part 와 unsorted part로 나뉜다
	for (int i = 0;i < n-1 ;i++)  //총 n-1번만 돌면 마지막 인덱스는 자동으로 정렬
	{
		//elements from i till n-1 are candidates
		int min = i;  //차례로 돌면서 최소값의 인덱스를 찾는것이다!
		for (int j = i + 1;j < n;j++)
		{
			if (A[j] < A[min])
			{
				min = j;  //update the index of minimum element
			}
	
		}
		swap(A[i], A[min]);//치명적인 실수... for loop안에 있는게 아니라 for 밖에!! 
		//최소수를 찾고 바꾼다
	}
}

void insertionsort(int * A, int n)
{
	for (int i = 1;i < n;i++)  //첫번째인덱스는 sorted subset로 분류 sorted 와 unsorted로 구분
	{
		int values = A[i];
		int hole = i;
		while (hole > 0 && A[hole - 1] > values)
		{
			A[hole] = A[hole - 1];//오른쪽으로 shift, copy
			hole--;
		}
		//마지막에 비교한 수와 values 값을 대입!
		A[hole] = values;

	}
}

void bubblesort(int * A, int n)
{
	for (int k = 0;k < n-1 ;k++)  // 0부터 n-2까지 측 n-1번 실행되면 마지막은 자동정렬
	{
		bool flag = false;
		for (int j = 0;j < n - k - 1;j++)  //맨 뒤에부터 정렬이된다
		{
			if (A[j] > A[j + 1]) //뒤에 숫자가 더 크다면 swap
			{
				swap( A[j], A[j+ 1]);
				flag = true;  //한버이라도 swap 되었으면 flag =true;
			}
		}
		//한번 pass하고 난후 flag가 여전히 false라면 정렬된 상태이므로 break;
		if (flag == false) break;
	}
}


int main(void)
{
	int n;
	scanf("%d", &n);
	int * A = (int *)malloc(sizeof(int)*n);

	for (int i = 0;i < n;i++)
		scanf("%d", &A[i]);


	//insertionsort(A, n);
	selectionsort(A, n);
	//bubblesort(A, n);
	for (int i = 0;i < n;i++)
		printf("%d", A[i]);
	free(A);
}