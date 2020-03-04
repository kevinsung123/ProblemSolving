#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MAX 101

int main(void){

	string a, b;

	cin >> a;

	for (int i = 0; i < a.size(); i++){
		if (a[i] >= 65 && a[i] <= 90){
			b.append(a.at[i]);
		}
	}

	cout << b;
}