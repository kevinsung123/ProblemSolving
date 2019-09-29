#include<iostream>
#include<list>
#include<algorithm>
#include<deque>
using namespace std;
const int MAX_N = 50;


int main()
{
	int N, M;
	int check[MAX_N] = { 0 };
	int ans = 0;
	deque<int> dq;
	
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	
	for (int i = 0; i < M; i++)
	{
		cin >> check[i];
	}


	//뽑아내려고하는 원소들의 최소 2 혹은 3번 연산을 구한다
	for (int i = 0; i < M; i++)
	{
		
		//해당원소이면  뽑는다
		if (dq.front() == check[i]) dq.pop_front();
		else
		{
			int idx = 0;
			//2번쨰 혹은 3번쨰 연산으로 최솟값을 구한다
			for (auto here : dq)
			{
				if (here == check[i]) break;
				idx++;
			}
			// l + r = dq.size()
			int l = idx;
			int r = dq.size() - idx;
			
		
			
			//2번째 연산
			if (l <= r)
			{
				//cout << "left" << l << endl;
				//해당원소 나올때 까지 pop
				while (dq.front() != check[i])
				{
					dq.push_back(dq.front());
					dq.pop_front();
					ans++;  //이동 횟수
				}
				//해당 원소이면 pop
				dq.pop_front();
				
			}
			else
			{
				//cout << "right" << r << endl;
				while (dq.front() != check[i])
				{
					dq.push_front(dq.back());
					dq.pop_back();
					ans++;
				}
				dq.pop_front();
			}

		/*	for (auto here : dq)
			{
				cout << here << " ";
			}
			cout << endl;*/
		}
	
	}
	cout << ans << endl;
}