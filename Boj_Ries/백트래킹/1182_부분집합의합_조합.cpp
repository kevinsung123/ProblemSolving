#include<iostream>
#include<vector>
using namespace std;

int currentSum, chk[20]; // 전역 합, 방문배열
int N, S, inPut[20]; //입력 파라미터
int ans;  //경우수 답


void comb(int cIdx, int uIdx,int cSum)  //cIdx번째 인덱스를 사용 여부 먼저 확인 확인하는 경우이므로 먼저 조건에 부합하는지 확인하고 그 다음 종결조건 지정
{
	/*cout << cIdx << ", "<<uIdx<<", " << cSum << endl;
	for (int i = 0; i < N; i++)cout << chk[i] << " ";
	cout << endl;*/

	if (cSum == S && cIdx > 0) ans++; //합이 S일떄


	if (cIdx > N  ) return;  //인덱스를 벗어날때

	


	for (int i = uIdx; i < N; i++)
	{
		if (chk[i] == 0) //아직 방문 안한경우라면
		{
			chk[i] = 1; 
			comb(cIdx + 1,i+1, cSum + inPut[i]); //현재인덱스를 포함시키는 경우 
			chk[i] = 0; //백트래킹할때 원래 상태로 복구
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> inPut[i];   // N개 입력 받음

	comb(0,0,0);

	cout << ans;
}