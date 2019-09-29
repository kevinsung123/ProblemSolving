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

	cout << "erathothenes factor:";
	cin >> num;
	eratostheness2();
	vector<int> fact = factor(num);

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

void eratosthenes()
{
	memset(isPrime, 1, sizeof(isPrime)); //isprime의 배열값을 크기만큼 1로 초기화
	//1은 항상 예외처리
	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt(era_num));
	for (int i = 2; i <= sqrtn; ++i){

		if (isPrime[i]){
			//i의 배수들 j들에 대해 isPrime[j]=false로 둔다
			//i*i 미만의 배수는 이미 지워졌으므로 신경쓰지 않는다
			for (int j = i*i; j <= era_num; j += i)
				isPrime[j] = false;
		}
	}
}

void eratosthenes2()//에라토스테네스의 체를 이용한 빠른 소인수 분해
{//minFactor[i]=i의 가장 작은 소인수(i가 소수인 경우 자기 자신)
	//1은 항상 예외처리
	minFactor[0] = minFactor[1] = -1;
	//모든 숫자를 처음에는 소수로 표시해둔다
	for (int i = 2; i <= num; i++)
		minFactor[i] = i;

	//에라토스테네스의 체를 수행한다
	int sqrtn = int(sqrt(num));
	for (int i = 2; i <= sqrtn; i++)
	{
		if (minFactor[i] == i)
		{
			for (int j = i*i; j <= num; j += i)
			{
				if (minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}
}

vector<int> factor(int n)
{
	vector<int> ret;
	//n이 1이 될떄까지 가장 작은 소인수로 나누기를 반복한다
	while (n > 1)
	{
		ret.push_back(minFactor[n]);
		n /= minFactor[n];
	}
}