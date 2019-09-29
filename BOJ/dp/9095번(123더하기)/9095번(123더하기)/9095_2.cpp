#include<iostream>
using namespace std;

int Partition(int n);


int main(void)
{
	int T;
	int * n;
	cin >> T;
	n = new int[T];
	for (int i = 0; i < T; i++)
		cin >> n[i];

	for (int i = 0; i < T; i++)
		cout << Partition(n[i]) << endl;



}

int Partition(int n){
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;

	return Partition(n - 1) + Partition(n - 2) + Partition(n - 3);

}