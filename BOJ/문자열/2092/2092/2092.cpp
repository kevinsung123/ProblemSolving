#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

#define MAX 101
char str[MAX];
char temp[MAX];

int main(void){

//	cin.getline(str, MAX); //���������� ���ڿ��� �Է¹޴´� 
	int index = 0;
	string A, B;
	cin >> A;

	for (int i = 0; i < A.size(); i++){
		if (A[i] >= 65 && A[i] <= 90){
			B.push_back(A[i]);
		}
	}

	cout << B << endl;

}