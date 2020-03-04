#include<cassert>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

// N ���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿���
// pi[] �� ����Ѵ�.
// pi[i] = N[..i] �� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
vector<int> getPartialMatchNaive(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	// �ܼ��� ���ڿ� Ž�� �˰����� �����Ѵ�
	for (int begin = 1; begin < m; ++begin) {
		for (int i = 0; i < m; ++i) {
			if (N[begin + i] != N[i]) break;
			// i + 1 ���ڰ� ���� �����Ǿ���.
			pi[begin + i] = __max(pi[begin + i], i + 1);
		}
	}
	return pi;
}

// N ���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿���
// pi[] �� ����Ѵ�.
// pi[i] = N[..i] �� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);

	// KMP �� �ڱ� �ڽ��� ã�´�

	// N �� N ���� ã�´�. begin=0 �̸� �ڱ� �ڽ��� ã�ƹ����ϱ� �ȵ�!
	int begin = 1, matched = 0;
	// ���� ���ڰ� N �� ���� ������ ������ ã���鼭 �κ� ��ġ�� ��� ����Ѵ�.
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}


// "¤����" H �� �κ� ���ڿ��� "�ٴ�" N �� �����ϴ� ���� ��ġ���� ��� ��ȯ�Ѵ�.
vector<int> naiveSearch(const string& H, const string& N) {
	vector<int> ret;
	// ��� ���� ��ġ�� �� �õ��� ����
	for (int begin = 0; begin + N.size() <= H.size(); ++begin) {
		bool matched = true;
		for (int i = 0; i < N.size(); ++i)
		if (H[begin + i] != N[i]) {
			matched = false;
			break;
		}
		if (matched) ret.push_back(begin);
	}
	return ret;
}

// "¤����" H �� �κ� ���ڿ��� "�ٴ�" N �� �����ϴ� ���� ��ġ���� ��� ��ȯ�Ѵ�.
vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;

	// pi[] �� �̸� ����Ѵ�
	// pi[i] = N[..i] �� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
	vector<int> pi = getPartialMatch(N);
	vector<int> pi2 = getPartialMatchNaive(N);
	if (pi != pi2){
		printf("N = %s\n", N.c_str());
		printf("pi ="); for (int i = 0; i < pi.size(); i++) printf(" %d", pi[i]); printf("\n");
		printf("pi2 ="); for (int i = 0; i < pi2.size(); i++) printf(" %d", pi2[i]); printf("\n");
		assert(pi == pi2);
	}

	// begin = matched = 0 �������� ��������
	int begin = 0, matched = 0;
	// begin �� �ִ밪�� n - m
	while (begin <= n - m) {
		// ���� ¤������ �ش� ���ڰ� �ٴ��� �ش� ���ڿ� ���ٸ�
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			// ��������� m ���ڰ� ��� ��ġ�ߴٸ� �信 �߰��Ѵ�
			if (matched == m) ret.push_back(begin);
		}
		else {
			// ����: matched �� 0 �� ��쿡�� ���� ĭ�������� ���
			if (matched == 0)
				++begin;
			else {
				// begin �� matched - pi[matched-1] ��ŭ �ű� �� �ִ�
				begin += matched - pi[matched - 1];
				// begin �� �Ű�ٰ� ó������ �ٽ� ���� �ʿ䰡 ����.
				// �ű� �Ŀ��� pi[matched-1] ��ŭ�� �׻� ��ġ�ϱ� �����̴�.
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

vector<int> kmpSearch2(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);

	// ���� ������ ������ ��
	int matched = 0;
	// ¤������ �� ���ڸ� ��ȸ�Ѵ�
	for (int i = 0; i < n; ++i) {
		// matched �� ���ڿ� ¤������ �ش� ���ڰ� ����ġ�� ���,
		// ���� ������ ������ ���� pi[matched-1] �� ���δ�
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		// ���ڰ� ������ ���
		if (H[i] == N[matched]) {
			++matched;
			if (matched == m) {
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}

	return ret;
}


/*
vector<int> naiveSearch(const string& H, const string& N) {
vector<int> ret;
for(int i = 0; i < H.size(); i++)
if(H.substr(i, N.size()) == N)
ret.push_back(i);
return ret;
}
*/

void printFailFunction(const string& N) {
	vector<int> overlap = getPartialMatch(N);
	vector<int> overlap2 = getPartialMatchNaive(N);
	printf("failure function for N %s:\n", N.c_str());
	for (int i = 0; i < overlap.size(); i++) {
		printf("%s: %d (%s)\n", N.substr(0, i + 1).c_str(), overlap[i], N.substr(0, overlap[i]).c_str());
		printf("%s: %d (%s)\n", N.substr(0, i + 1).c_str(), overlap2[i], N.substr(0, overlap2[i]).c_str());
	}
}

void testSearch(const string& H, const string& N) {
	//printf("testing H [%s] N [%s]\n", H.c_str(), N.c_str());
	vector<int> a = naiveSearch(H, N);
	vector<int> b = kmpSearch(H, N);
	if (a != b) {
		printf("H [%s] N [%s]\n", H.c_str(), N.c_str());
		printf("naive [");
		for (int i = 0; i < a.size(); i++) printf("%s%d", (i ? ", " : ""), a[i]);
		printf("] kmp [");
		for (int i = 0; i < b.size(); i++) printf("%s%d", (i ? ", " : ""), b[i]);
		printf("]\n");
		//printf("naive %d kmp1 %d kmp2 %d\n", a, b, c);
		assert(false);
	}
}

void testSearch2(const string& H, const string& N) {
	//printf("testing H [%s] N [%s]\n", H.c_str(), N.c_str());
	vector<int> a = kmpSearch(H, N);
	vector<int> b = kmpSearch2(H, N);
	if (a != b) {
		printf("H [%s] N [%s]\n", H.c_str(), N.c_str());
		printf("kmp1 [");
		for (int i = 0; i < a.size(); i++) printf("%s%d", (i ? ", " : ""), a[i]);
		printf("] kmp2 [");
		for (int i = 0; i < b.size(); i++) printf("%s%d", (i ? ", " : ""), b[i]);
		printf("]\n");
		//printf("naive %d kmp1 %d kmp2 %d\n", a, b, c);
		assert(false);
	}
}

string toString(int mask, int len) {
	string ret;
	for (int i = 0; i < len; i++)
	if (mask & (1 << i))
		ret += 'a';
	else
		ret += 'b';
	return ret;
}

void testAll(int h, int n) {
	for (int i = 0; i < (1 << h); i++) {
		string H = toString(i, h);
		for (int j = 0; j < (1 << n); j++) {
			string N = toString(j, h);
			testSearch2(H, N);
		}
	}
}

int main() {
	printFailFunction("aabaabac");
	testSearch2("abaabaabaabbbaabb", "aabaa");
	testSearch2("abaabaabaabbbaabb", "aabb");
	printFailFunction("ababaca");
	printFailFunction("abrabadabra");
	testSearch2("abracadabra", "aca");
	testSearch2("abracadabra", "acba");
	testSearch2("abracadabra", "abr");
	for (int h = 4; h <= 16; ++h) {
		for (int n = 1; n <= 6; n++) {
			testAll(h, n);
			printf("passed h=%d n=%d ..\n", h, n);
		}
	}
	printf("all done.\n");
}

