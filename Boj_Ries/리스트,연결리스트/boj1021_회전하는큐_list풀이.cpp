#include<iostream>
#include<list>
#include<deque>
#include<algorithm>
using namespace std;
const int MAX_N = 50;

int main()
{
	int N, M;
	cin >> N >> M;
	//회전하는 큐
	int arr[MAX_N] = { 0, };

	//사용하려는 자료구조 및 변수
	list<int> L;
	list<int>::iterator iter;
	int ans = 0;

	for (int i = 1; i <= N; i++) L.push_back(i);

	//찾으려는 수들
	for (int i = 0; i < M; i++)
	{
		int in, l, r;
		int idx = 0;
		cin >> in;
		
		//첫번쨰수 뽑는 경우
		if (in == L.front()) L.pop_front();
		//2 또는 3번째 연산하는 경우
		else
		{
			for (auto here : L)
			{
				if (here == in) break;
				idx++;
			}
			//2 또는 3번 연산 횟수
			l = idx;
			r = L.size() - idx;

			//2번째 연산하는 경우 왼쪽으로 회전
			if (l < r)
			{
				// l번만큼 회전
				for (int i = 0; i < l; i++)
				{
					int tmp = L.front();
					L.push_back(tmp);
					L.pop_front();
					ans++;  //2번 연산 횟수
				}

				//해당 숫자가 맨 앞에 오면
				L.pop_front();
			}
			else
			{
				//r번 만큼 오른쪽 회전
				for (int i = 0; i < r; i++)
				{
					int tmp = L.back();
					L.push_front(tmp);
					L.pop_back();
					ans++;  //3번 연산 횟수
				}
				//해당 숫자 찾으면 
				L.pop_front();
			}

		}
	}
	cout << ans << endl;

}