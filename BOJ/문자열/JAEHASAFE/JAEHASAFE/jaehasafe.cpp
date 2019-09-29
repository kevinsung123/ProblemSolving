#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<int> getpartialmatch(string a, string b);
int kmpsearch(string a, string b);
int shift(string a, string b);


vector<int> kmpresult;

int main(void)
{
	cin.sync_with_stdio(false);
	int T;
	int N;
	
	cin >> T;
	while (T--){
		cin >> N;
		N++;
		vector<string> input(N);
		
		cin >> input[0];

		int sum = 0;
		for (int i = 1; i <N; i++){
			cin >> input[i];

			
			
			int turn = i % 2;
			int search;
			
			if (turn){  //turn=0�̸� Ȧ���̹Ƿ� �ð����
				search = kmpsearch(input[i] + input[i], input[i - 1]);
	
			}
			else{  //turn ¦���̸� �ð�ݴ� ����
				search = kmpsearch(input[i - 1] + input[i - 1], input[i]);
			}
			//cout << "search=" << search << endl;
			sum += search;
		}
		cout << sum<<endl;

	}


	return 0;

}

vector<int> getpartialmatch(string a )
{
	int n = a.size();
	
	vector<int> pi(n, 0);
	int begin = 1, matched = 0;

	while (begin + matched < n){

		if (a[begin + matched] == a[matched])
		{
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else{

			if (matched == 0) 
				++begin;
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}//while end
	return pi;
}

int kmpsearch(string a, string b)
{
	int n = a.size();
	int m = b.size();

	vector<int> ans(n, 0);  //���� ���� vector  orginal�� ũ�� ����
	vector<int> pi = getpartialmatch(b);  //pattern �� �κ���ġ�迭 

	//int begin = 0, matched = 0;
	//while (begin<= n-m){
	//	if (a[begin + matched] == b[matched] && matched < m)
	//	{
	//		++matched;
	//		if (matched == m){
	//			ans.push_back(begin); //matched=m�̸� �� �ش��ϴ� ��ġ�� ����� ����
	//			return  begin - m + 1;

	//		}
	//		else{
	//			if (matched == 0) ++begin;//matched=0�̸� �� ���� ���ڸ� ��
	//			else{
	//				begin += matched - pi[matched - 1]; //�״��� ��ġ�� ���ϱ� ���� 
	//			}
	//		}
	//	}
	//	return -1;
	//}
	int matched = 0;
	for (int i = 0; i < n; i++){

		while (matched>0 && a[i] != b[matched])
			matched = pi[matched - 1];
		if (a[i] == b[matched]){
			++matched;
			if (matched == m)
				return i - m + 1;
		}
	}
	return -1;

}
//
//int shift(string a, string b)
//{
//	return kmpsearch(a + a, b)[0]; //kmp�� search �ҋ� �� �տ� �ִ¼��� 
//}