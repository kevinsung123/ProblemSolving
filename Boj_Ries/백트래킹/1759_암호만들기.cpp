#include<iostream>
#include<algorithm>
using namespace std;

char alpha[16];
char match[16];
bool chk[16];
bool isVowel[26]; //모음 판단
int L, C;


void dfs(int idx, int prev)  //match에서 채워진 idx 수,alpha에서 사용된 prev
{
	if (idx == L) //match idx개수만큼 다채워졌으면
	{
		int vowel = 0;  //모음
		int consonant = 0; //자음

		//조합으로 만들어 암호값들 자음 모음 확인 
		for (int i = 0; i < idx; i++)
		{
			if (isVowel[match[i] - 'a'] == true) vowel++;
			else consonant++;
		}

		if (vowel >= 1 && consonant >= 2)  //모음 1개 자음 2개 이상이면 조건 충족
			cout << match << endl;

		return;

	}

	//아직 사용하지않은 암호들을 모두 시도
	for (int i = prev; i < C; i++)
	{
		if (!chk[i])//방문하지않으면
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