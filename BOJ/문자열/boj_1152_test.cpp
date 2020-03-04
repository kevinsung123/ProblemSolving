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
		cout << "for�� ��" << endl;
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		cout << "forfor��" << endl;
		if (arr[i] == 0) 
			continue; //�̹� üū�� ���� ����� Ȯ������ �ʴ´�

		for (int j = i + i; j <= n; j += i) {
			cout << "forfor��2����" << endl;
			arr[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] != 0) cout << arr[i] << " ";
	}
}