#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int TM = 1000 * 1000 * 10;
int minfactor[TM + 1];  //i의 가장 작은 소인수 minfactor[i]=i  (i가 소수인경우 자기 자신)
int minfactorpower[TM + 1];  // minfactorpower[i]=i의 소인수 분해에는 minfactor[i]가 몇승이 포함되는가?
int factor[TM + 1]; //factor[i]=i가 가진 약수의 수 

void getfactorsmart()
{
	factor[1] = 1;  //1의 약수는 자기 자신 1개

	//에네토스테네스의 체를 이용해 minfactor[i]=i구함
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
			if (minfactor[j] == j)//아직 약수를 본적이 없는경우
				minfactor[j] = i;
		}
	}

	for (int n = 2; n <= TM; ++n)
	{
		//소수인 경우 약수가 2개밖에 없다.
		if (minfactor[n] == n)
		{
			minfactorpower[n] = 1;
			factor[n] = 2;
		}
		//소수가 아닌 경우, 가장 작은 소인수로 나눈수 (m)의 약수의수를 응용해 n의 약수를 찾는다
		else
		{
			int p = minfactor[n];
			int m = n / p; //n은 원래수의 p는 n의 가장 작은 소인수
			//m이 더상 p로 나누어 지지않은경우
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