#include <iostream>

using namespace std;

int main(void)
{
	
	int T;
	int *num;
	int i = 0;
	int A[12] = { 0 };
	A[0] = 0;
	A[1] = 1;
	A[2] = 2;
	A[3] = 4;

	for (int i = 4; i <= 11; i++){
		
		A[i] = A[i - 1] + A[i - 2] + A[i - 3];
	}

	//����Ǽ� T�� �Է¹���
	cin >> T;
	num = new int[T];
	//num = new int[T];
	//for (int i = 0; i < T; i++)
	//		cin >> num[i];

	////������ ��쿡���� �����
	//for (int i = 0; i < T; i++){
	//	int n = num[i];
	//	cout << A[n] << endl;
	//}
	//delete []num;
	int n = T;
	while (T--){
		cin >> num[i++];
	}

	for (int i = 0; i < n; i++)
		cout << A[num[i]] << endl;

}