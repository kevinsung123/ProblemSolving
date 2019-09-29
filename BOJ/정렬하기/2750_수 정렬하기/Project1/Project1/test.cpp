#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;


void selectionsort(int * A, int n)
{
	//n-2 passes  sorted part �� unsorted part�� ������
	for (int i = 0;i < n-1 ;i++)  //�� n-1���� ���� ������ �ε����� �ڵ����� ����
	{
		//elements from i till n-1 are candidates
		int min = i;  //���ʷ� ���鼭 �ּҰ��� �ε����� ã�°��̴�!
		for (int j = i + 1;j < n;j++)
		{
			if (A[j] < A[min])
			{
				min = j;  //update the index of minimum element
			}
	
		}
		swap(A[i], A[min]);//ġ������ �Ǽ�... for loop�ȿ� �ִ°� �ƴ϶� for �ۿ�!! 
		//�ּҼ��� ã�� �ٲ۴�
	}
}

void insertionsort(int * A, int n)
{
	for (int i = 1;i < n;i++)  //ù��°�ε����� sorted subset�� �з� sorted �� unsorted�� ����
	{
		int values = A[i];
		int hole = i;
		while (hole > 0 && A[hole - 1] > values)
		{
			A[hole] = A[hole - 1];//���������� shift, copy
			hole--;
		}
		//�������� ���� ���� values ���� ����!
		A[hole] = values;

	}
}

void bubblesort(int * A, int n)
{
	for (int k = 0;k < n-1 ;k++)  // 0���� n-2���� �� n-1�� ����Ǹ� �������� �ڵ�����
	{
		bool flag = false;
		for (int j = 0;j < n - k - 1;j++)  //�� �ڿ����� �����̵ȴ�
		{
			if (A[j] > A[j + 1]) //�ڿ� ���ڰ� �� ũ�ٸ� swap
			{
				swap( A[j], A[j+ 1]);
				flag = true;  //�ѹ��̶� swap �Ǿ����� flag =true;
			}
		}
		//�ѹ� pass�ϰ� ���� flag�� ������ false��� ���ĵ� �����̹Ƿ� break;
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