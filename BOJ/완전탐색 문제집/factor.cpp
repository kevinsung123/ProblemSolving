#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 10000

bool isprime(int n); //소수 판별 알고리즘
vector<int> factorSimple(int n); //소인수 분해 
void eratostheness2();
bool isPrime[MAX + 1];
int minFactor[MAX];
int era_num;
int num;
vector<int> factor(int n);

int main(void)
{
	int n;
	cin >> n;
	vector<int> ans = factorSimple(n);

	for (size_t i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	

}

bool isprime(int n) //소수 판별 알고리즘
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	int sqrtn = int(sqrt(n));
	for (int div = 3; div <= sqrtn; div += 2){
		if (n% div == 0) return false;
	}
	return true;
}

vector<int> factorSimple(int n){ //소인수분해 
	vector<int> ret;
	int sqrtn = int(sqrt(n));
	for (int div = 2; div <= sqrtn; div++){
		while (n%div == 0){
			n /= div;
			ret.push_back(div);
		}
	}
	//if (n > 1) ret.push_back(n);
	return ret;
}

