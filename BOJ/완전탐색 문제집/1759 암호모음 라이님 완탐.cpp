#include <cstdio>
#include <algorithm>
using namespace std;

int L, C;
char A[15], P[16];
bool isVowel[26];

void backtrack(int pos, int prev, int consonant, int vowel) {
	// L���� ���ڸ� �� �� ���: ���ǿ� ������ ���� ��ȣ ����ϰ� ����
	if (pos == L) {
		if (consonant >= 2 && vowel >= 1) puts(P);
		return;
	}

	// ���� ������� ���� ��ȣ�� �ϳ��� �õ�
	for (int i = prev + 1; i<C; i++) {
		P[pos] = A[i];
		backtrack(pos + 1, i, consonant + !isVowel[A[i] - 'a'], vowel + isVowel[A[i] - 'a']);
		// P[pos]�� ������ �ٽ� ������� ���̹Ƿ� �� �������� ��
	}
}

int main() {
	scanf("%d %d", &L, &C);
	for (int i = 0; i<C; i++)
		scanf(" %c", A + i);
	sort(A, A + C);
	isVowel[0] = isVowel[4] = isVowel[8] = isVowel[14] = isVowel[20] = true;
	backtrack(0, -1, 0, 0);
}


