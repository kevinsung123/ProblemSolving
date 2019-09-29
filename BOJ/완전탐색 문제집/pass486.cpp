#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int TM = 1000 * 1000 * 10;
int minfactor[TM + 1];  //i�� ���� ���� ���μ� minfactor[i]=i  (i�� �Ҽ��ΰ�� �ڱ� �ڽ�)
int minfactorpower[TM + 1];  // minfactorpower[i]=i�� ���μ� ���ؿ��� minfactor[i]�� ����� ���ԵǴ°�?
int factor[TM + 1]; //factor[i]=i�� ���� ����� �� 

void getfactorsmart()
{
	factor[1] = 1;  //1�� ����� �ڱ� �ڽ� 1��

	//�����佺�׳׽��� ü�� �̿��� minfactor[i]=i����
	minfactor[0] = minfactor[1] = -1;
	for (int i = 2; i <= TM; i++){
		minfactor[i] = i;
		
	}
	int sqrn = sqrt(TM);
	for (int i = 2; i <= sqrn; i++)
	{
		if (minfactor[i] == i)  
		{
			for (int j = i*i; j <= TM;j+=i)
			if (minfactor[j] == j)//���� ����� ������ ���°��
				minfactor[j] = i;
		}
	}

	for (int n = 2; n <= TM; ++n)
	{
		//�Ҽ��� ��� ����� 2���ۿ� ����.
		if (minfactor[n] == n)
		{
			minfactorpower[n] = 1;
			factor[n] = 2;
		}
		//�Ҽ��� �ƴ� ���, ���� ���� ���μ��� ������ (m)�� ����Ǽ��� ������ n�� ����� ã�´�
		else
		{
			int p = minfactor[n];
			int m = n / p; //n�� �������� p�� n�� ���� ���� ���μ�
			//m�� ���� p�� ������ �����������
			if (p != minfactor[m])
				minfactorpower[n] = 1;
			else
				minfactorpower[n] = minfactorpower[m] + 1;
			int a = minfactorpower[n];
			factor[n] = (factor[m] / a)*(a + 1);
		}

	}
}

void getfactorbrute()
{
	memset(factor, 0, sizeof(factor));
	for (int div = 1; div <= TM;++div)
	for (int multiple = div; multiple <= TM; multiple += div)
		factor[multiple] += 1;
}


int main(void)
{
	ios::sync_with_stdio(false);

	int C, N, lo, hi;
	cin >> C;
	getfactorsmart();
	while (C--)
	{
		int cnt = 0;
		cin >> N >> lo >> hi;
		for (int i = lo; i <= hi; i++)
		{
			if (factor[i] == N)
				cnt++;
		}
		cout << cnt << endl;
	}
	
	


	
	
		
}