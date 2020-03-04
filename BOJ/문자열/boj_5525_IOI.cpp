#include<iostream>
#include<string>
#include<vector>
using namespace std;

string setting(int n);
int kmpsearch(string A, string B);
vector<int> getpartial(string B);

int main(void)
{
	string S, pat;
	int N, M;
	int ans;
	//N,M,S �Է¹���1
	cin >> N;
	cin>> M;
	cin >> S;
	pat = setting(N);
	//cout << pat;
	ans = kmpsearch(S, pat);
	cout << ans << endl;

}

string setting(int n)
{
	string a = "I";
	for (int i = 0; i < n; i++){
		a+="OI";
	}
	return a;
}

int kmpsearch(string A, string B)
{
	int a = A.size();
	int b = B.size();

	vector<int> ans;
	vector<int> pi = getpartial(B);
	int count = 0;
	int begin = 0;
	int matched = 0;

	while (begin <= a - b){

		if (A[begin + matched] == B[matched]){
			++matched;
			if (matched == b){  //ã�� ������ ������ ã���� 
				ans.push_back(begin); //ã�� ������ ���ڿ��� ù���� ��ġ�� ����
				count++;
			}
		}
		else{
			if (matched == 0)
				begin++; //�ƹ��͵� ��ġ���������� �Ѱ��� ����
			else{
				begin += (matched-pi[matched - 1]);
				matched = pi[matched - 1];
			}
		}
	}

	return count;

	 
}


vector<int> getpartial(string pat)
{
	int a = pat.size();
	int begin = 1;  //�ֳ��ϸ� �ڽ��� ���ڿ��� �ڽ��� ã�µ� begin=0�̸� ������ ��ġ�ϹǷ� begin =1���� ����
	int matched = 0; // ũ�� a�̰� 0���� �ʱ�ȭ
	vector<int> pi(a, 0);

	while (begin + matched < a){
		if (pat[begin + matched] == pat[matched]){
			++matched;
			pi[begin+matched-1] = matched;
		}
		else{
			if (matched == 0) ++begin;
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}


	}

	return pi;
}