#include<iostream>
#include<vector>
using namespace std;

int currentSum, chk[20]; // ���� ��, �湮�迭
int N, S, inPut[20]; //�Է� �Ķ����
int ans;  //���� ��


void comb(int cIdx, int uIdx,int cSum)  //cIdx��° �ε����� ��� ���� ���� Ȯ�� Ȯ���ϴ� ����̹Ƿ� ���� ���ǿ� �����ϴ��� Ȯ���ϰ� �� ���� �������� ����
{
	/*cout << cIdx << ", "<<uIdx<<", " << cSum << endl;
	for (int i = 0; i < N; i++)cout << chk[i] << " ";
	cout << endl;*/

	if (cSum == S && cIdx > 0) ans++; //���� S�ϋ�


	if (cIdx > N  ) return;  //�ε����� �����

	


	for (int i = uIdx; i < N; i++)
	{
		if (chk[i] == 0) //���� �湮 ���Ѱ����
		{
			chk[i] = 1; 
			comb(cIdx + 1,i+1, cSum + inPut[i]); //�����ε����� ���Խ�Ű�� ��� 
			chk[i] = 0; //��Ʈ��ŷ�Ҷ� ���� ���·� ����
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> inPut[i];   // N�� �Է� ����

	comb(0,0,0);

	cout << ans;
}