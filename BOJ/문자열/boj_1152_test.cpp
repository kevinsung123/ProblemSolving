#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;


void sieve(int n);

int main(void)
{

	sieve(20);
}

void sieve(int n)
{
	vector<int> arr(n+2);
	for (int i = 2; i <= n; i++) {
		cout << "for문 안" << endl;
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		cout << "forfor문" << endl;
		if (arr[i] == 0) 
			continue; //이미 체큰된 수의 배수는 확인하지 않는다

		for (int j = i + i; j <= n; j += i) {
			cout << "forfor문2번쨰" << endl;
			arr[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] != 0) cout << arr[i] << " ";
	}
}