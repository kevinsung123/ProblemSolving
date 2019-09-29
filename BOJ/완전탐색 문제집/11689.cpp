#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(void)
{

	ios::sync_with_stdio(false);

	long long n;
	cin >> n;
	long long product = n;
	

	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	//소인수 분해
	vector<long long> ret;


	for (long long int div = 2; div*div <= n; div++){
		while (n%div == 0){
			n /= div;
			ret.push_back(div);
		}
	}
	if (n > 1) ret.push_back(n);
	

	
	//오일러 피함수 
	long long ans = product;

	
	ans = ans*((long double)(ret[0] - 1) / ret[0]);
	
	for (size_t i = 1; i < ret.size(); i++)
	{
		if (ret[i] != ret[i - 1])
			ans = ans*((long double)(ret[i]-1)/ret[i]);
		
		
	}
	
	printf("%lld", ans);
}




