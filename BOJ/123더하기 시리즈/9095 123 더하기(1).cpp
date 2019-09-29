#include <iostream>

using namespace std;

int main(void)
{
	int A[11] = { 0 };
	int T;
	int *num;
	int Part[11] = { 0 };



	A[0] = 0;
	A[1] = 1;
	A[2] = 2;
	A[3] = 4;

	for (int i = 4; i <= 11; i++) {

		A[i] = A[i - 1] + A[i - 2] + A[i - 3];
	}

	//경우의수 T를 입력받음
	cin >> T;
	num = new int[T];
	for (int i = 0; i < T; i++)
		cin >> num[i];

	//각각의 경우에대해 출력함
	for (int i = 0; i < T; i++)
		cout << A[num[i]] << endl;





}