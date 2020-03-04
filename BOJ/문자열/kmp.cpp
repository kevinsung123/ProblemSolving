#include<vector>
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
vector<int> naivesearch(const string&H, const string &N);
vector<int> kmpsearch(const string&H, const string &N);
vector<int> getPartialMatch(const string &N);

int main(void)
{
	clock_t begin, end;
	string H;
	string N;
	cin >> H >> N;

	vector<int> answer;
	begin = clock();
	answer = kmpsearch(H, N);
	end = clock();
	for (size_t i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	printf("\"clocktime=%0.6f", (begin - end) / CLOCKS_PER_SEC);



}

vector<int> naivesearch(const string&H, const string&N)
{
	vector<int> ret;
	//��� ���� ��ġ�� �� �õ��غ���
	for (int begin = 0; begin + N.size() <= H.size(); begin++){
		bool matched = true;
		for (size_t i = 0; i < N.size(); ++i){
			if (H[begin + i] != N[i]){
				matched = false;
				break;
			}	
		}
		if (matched) ret.push_back(begin);
	}
	return ret;
}

vector<int> kmpsearch(const string &H, const string &N)
{
	//�񱳿����� size ũ��
	int n = H.size();

	//�񱳴���� size ũ��
	int m = N.size();

	//���� �����ϴ� ret
	vector<int> ret;
	//���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ����
	vector<int> pi = getPartialMatch(N);
	
	int begin = 0;
	int matched = 0; //��ġ�ѱ��ڼ�

	while (begin <= n - m){
		//���� ���ٸ�
		if (matched < m && H[begin + matched] == N[matched]){
			++matched;
			//��������� m���ڰ� ��� ��ġ�ߴٸ� �信 �߰�
			if (matched == m) ret.push_back(begin);
			
		}
		else
		{
			if (matched == 0) ++begin;
			else{
				begin += matched - pi[matched - 1];
				//begin�� �Ű�ٰ� �ϴ��� ó������ �ٽ� �����ʿ����
				//�ű� �Ŀ��� pi[matched-1]��ŭ�� �׻� ��ġ�ϱ� �����̴�
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}


//N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ���ġ�� �̿��� 
//pi[]�� ����Ѵ�
//pi[..i]=N[,..i
vector<int> getPartialMatch(const string & N){
	int m = N.size();
	vector<int> pi(m, 0); //ũ�� m�̰� 0���� �ʱ�ȭ
	//KMP�� �ڱ� �ڽ��� ã�´�
	//N���� N�� ã�´�. begin=0�̸� �ڱ� �ڽ��̹Ƿ� begin=1����
	int begin = 1;
	int matched = 0;
	while (begin + matched < m){
		if (N[begin + matched] == N[matched]){
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else{
			if (matched == 0)
				++begin;//��ġ�ϴ� ���ڰ������� �� ����
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;

	
}