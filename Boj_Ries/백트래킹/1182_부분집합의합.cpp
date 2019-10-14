#include<iostream>
#include<algorithm>
using namespace std;

int N, S, idx[20];
int cnt, currentSum;


void dfs(int current) //�迭�� ����� ���� �ε��� => ��Ʈ��ŷ �� ����
{

	if (current == N) return;  //�ε��� �ʰ���

	//������� ���� S�̸� cnt++
	if (currentSum + idx[current] == S) cnt++;

	//���� ���� ����X �ϴ°��
	dfs(current + 1);

	//���� ���� ���Խ� 
	currentSum += idx[current];
	dfs(current + 1);

	//��Ʈ��ŷ ���������� �����ذ� ����

	currentSum -= idx[current];
}

int main()
{
	//ios::sync_with_stdio(false);

	cin >> N >> S;


	for (int i = 0; i < N; i++) cin >> idx[i]; //N���� ���� �Է¹���


	dfs(0);

	cout << cnt << endl;


}