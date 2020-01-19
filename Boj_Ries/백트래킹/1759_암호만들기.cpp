#include<iostream>
#include<algorithm>
using namespace std;

char alpha[16];
char match[16];
bool chk[16];
bool isVowel[26]; //���� �Ǵ�
int L, C;


void dfs(int idx, int prev)  //match���� ä���� idx ��,alpha���� ���� prev
{
	if (idx == L) //match idx������ŭ ��ä��������
	{
		int vowel = 0;  //����
		int consonant = 0; //����

		//�������� ����� ��ȣ���� ���� ���� Ȯ�� 
		for (int i = 0; i < idx; i++)
		{
			if (isVowel[match[i] - 'a'] == true) vowel++;
			else consonant++;
		}

		if (vowel >= 1 && consonant >= 2)  //���� 1�� ���� 2�� �̻��̸� ���� ����
			cout << match << endl;

		return;

	}

	//���� ����������� ��ȣ���� ��� �õ�
	for (int i = prev; i < C; i++)
	{
		if (!chk[i])//�湮����������
		{
			chk[i] = 1;
			match[idx] = alpha[i];  
			dfs(idx + 1, i + 1);
			chk[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> alpha[i];
	sort(alpha, alpha + C);
	isVowel[0] = isVowel[4] = isVowel[8] = isVowel[14] = isVowel[20] = true;
	dfs(0, 0);
	

}