#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<int> getpartialmatch(string a, string b);
vector<int> kmpsearch(string a, string b);
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
				search = shift(input[i], input[i - 1]);

			}
			else{  //turn ¦���̸� �ð�ݴ� ����
				search = shift(input[i - 1], input[i]);
			}
			//cout << "search=" << search << endl;
			sum += search;
		}
		cout << sum << endl;

	}
	
	//for (int i = 0; i < kmpresult.size(); i++)
		//cout <<"kmpresult"<< kmpresult[i] << ", ";


	return 0;

}

vector<int> getpartialmatch(string a)
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

vector<int> kmpsearch(string a, string b)
{
	int n = a.size();
	int m = b.size();
	//cout << "m=" << m << endl;
	vector<int> ans;  //���� ���� vector  orginal�� ũ�� ����
	vector<int> pi = getpartialmatch(b);  //pattern �� �κ���ġ�迭 

	int begin = 0, matched = 0;
	while (begin<= n-m)
	{
		if (matched < m && a[begin + matched] == b[matched])
		{
			++matched;
			//cout << "match=" << matched << ",begin" << begin << endl;
			if (matched == m) {
			//	cout << "matched=m" << " ->begin =" << begin << endl;
				ans.push_back(begin); //matched=m�̸� �� �ش��ϴ� ��ġ�� ����� ����
				}
		}
		else{
				if (matched == 0) ++begin;//matched=0�̸� �� ���� ���ڸ� ��
				else{
					begin += matched - pi[matched - 1]; //�״��� ��ġ�� ���ϱ� ���� 
					matched = pi[matched - 1];
				}
		}
		
	
	}//while end
	return ans;
	
}

int shift(string a, string b)
{
	kmpresult = kmpsearch(a + a, b);
	
	return kmpsearch(a + a, b)[0];; //kmp�� search �ҋ� �� �տ� �ִ¼��� 
}