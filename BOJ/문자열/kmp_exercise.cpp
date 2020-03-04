#include<vector>
#include<iostream>
#include<string>
using namespace std;

vector<int> naivesearch(string &H, string &N);
vector<int> kmpsearch(string &H, string &N);
vector<int> partialmatch(string &N);


int main(void)
{
	string a, b;
	cin >> a >> b;
	
	vector<int> answer;

	answer = kmpsearch(a, b);

	for (size_t i = 0; i < answer.size(); i++)
		printf("%s%d", (i ? "," : ""), answer[i]);
		/*cout << answer[i] << " ";*/



}

vector<int> naivesearch(string &H, string &N){
	vector<int> ret;
	int h = H.size();
	int n = N.size();

	for (int begin = 0; begin + n <= h; begin++){
		bool matched = true;
		for (int i = 0; i < n; i++){
			if (H[begin + i] != N[i]){
				matched = false;
				break;  //���� mismatch�ϸ� for���� ���

			}
		}
		if (matched) ret.push_back(begin);//��ġ�ϸ� �� ��ġ�� vector�� ����

		return ret;
	}
}
		


vector<int> kmpsearch(string &H, string &N)
{
	vector<int> ret; //return ���� vector ��
	int h = H.size();
	int n = N.size();

	int begin = 0;  //���� ��ġ
	int matched = 0; //match�� ���ڼ�
	vector<int> pi = partialmatch(N);

	while (begin <= h - n){
		//���� ���ٸ�
		if (matched < n && H[begin + matched] == N[matched]){
			++matched; //��ġ�Ѵٸ� matched �Ѱ��� ����
			if (matched == n) ret.push_back(begin);  //��� ���ٸ� �� ������ġ�� push_back
		}
		else{
			if (matched == 0) begin++; //match�� ���ڰ� �ƹ��͵� ������ ������ġ1 ����
			else
			{
				begin += matched - pi[matched - 1];  //�κй迭�� �̿��Ͽ� ������ġ ����
				matched = pi[matched - 1];
			}
		}

	}
	return ret;

	
}

vector<int> partialmatch(string &N)
{
	int n = N.size();
	vector<int> pi(n, 0);

	//N���� �ڱ��ڽ��� match�Ѵ�. �ڱ��ڽŰ� ������ �ȵǹǷ� begin!=0
	int begin = 1;
	int matched = 0;

	while (begin + matched < n){
		if (N[begin + matched] == N[matched]){
			++matched;
			pi[begin + matched - 1] = matched;
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