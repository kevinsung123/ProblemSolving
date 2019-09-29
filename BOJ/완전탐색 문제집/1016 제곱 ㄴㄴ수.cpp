#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	long long min, max;
	scanf("%lld %lld", &min, &max);
	/*
	isP[i]: i�� �Ҽ��� true
	�ִ� ũ�Ⱑ �̷��� ������ ������ max�� �ִ밪�� �������̾
	*/
	bool isP[1001002];
	memset(isP, 1, sizeof(isP));
	// �����佺�׳׽��� ü�� �Ҽ����� �̾� vector�� ����
	vector<int> prime;
	prime.push_back(2);
	int limit = sqrt(max) + 1;
	for (int i = 3; i<limit; i += 2) {
		if (!isP[i]) continue;
		prime.push_back(i);
		// ����: i�� ũ�� i*i�� int ������ �Ѿ �� ����
		for (long long j = 1LL * i*i; j<limit; j += i * 2)
			isP[j] = false;
	}

	// �������� isP[i]: i-min�� ������������ true
	memset(isP, 1, sizeof(isP));
	for (int p : prime) {
		// ��� �Ҽ��� ���ؼ� �־��� ���� �ȿ����� ü�� �Ÿ���
		long long n = 1LL * p*p;
		// i�� ���� �ε����� min �̻��� �ּ��� p*p�� ���
		//min%n min�̻��̸鼭 n�� �������� ������
		//(min/n+1)*n �� min�̻��̸鼭 n�� ������
		//������ �������� �׳� min
		for (long long i = (min%n ? (min / n + 1)*n : min); i <= max; i += n)
		{
			//printf("n=%lld, i=%lld, min=%lld, i-min=%lld \n",n ,i,min, i - min);
			isP[i - min] = false;
		}
		
	}

	// ü�� �ɷ����� ���� ĭ�� ������ ��
	int result = 0;
	for (int i = 0; i<max - min + 1; i++)
		result += isP[i];
	printf("%d\n", result);
}


