#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 10000

bool isprime(int n); //�Ҽ� �Ǻ� �˰���
vector<int> factorSimple(int n); //���μ� ���� 
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

bool isprime(int n) //�Ҽ� �Ǻ� �˰���
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

vector<int> factorSimple(int n){ //���μ����� 
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
	memset(isPrime, 1, sizeof(isPrime)); //isprime�� �迭���� ũ�⸸ŭ 1�� �ʱ�ȭ
	//1�� �׻� ����ó��
	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt(era_num));
	for (int i = 2; i <= sqrtn; ++i){

		if (isPrime[i]){
			//i�� ����� j�鿡 ���� isPrime[j]=false�� �д�
			//i*i �̸��� ����� �̹� ���������Ƿ� �Ű澲�� �ʴ´�
			for (int j = i*i; j <= era_num; j += i)
				isPrime[j] = false;
		}
	}
}

void eratosthenes2()//�����佺�׳׽��� ü�� �̿��� ���� ���μ� ����
{//minFactor[i]=i�� ���� ���� ���μ�(i�� �Ҽ��� ��� �ڱ� �ڽ�)
	//1�� �׻� ����ó��
	minFactor[0] = minFactor[1] = -1;
	//��� ���ڸ� ó������ �Ҽ��� ǥ���صд�
	for (int i = 2; i <= num; i++)
		minFactor[i] = i;

	//�����佺�׳׽��� ü�� �����Ѵ�
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
	//n�� 1�� �ɋ����� ���� ���� ���μ��� �����⸦ �ݺ��Ѵ�
	while (n > 1)
	{
		ret.push_back(minFactor[n]);
		n /= minFactor[n];
	}
}