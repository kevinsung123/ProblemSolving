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


	//�̾Ƴ������ϴ� ���ҵ��� �ּ� 2 Ȥ�� 3�� ������ ���Ѵ�
	for (int i = 0; i < M; i++)
	{
		
		//�ش�����̸�  �̴´�
		if (dq.front() == check[i]) dq.pop_front();
		else
		{
			int idx = 0;
			//2���� Ȥ�� 3���� �������� �ּڰ��� ���Ѵ�
			for (auto here : dq)
			{
				if (here == check[i]) break;
				idx++;
			}
			// l + r = dq.size()
			int l = idx;
			int r = dq.size() - idx;
			
		
			
			//2��° ����
			if (l <= r)
			{
				//cout << "left" << l << endl;
				//�ش���� ���ö� ���� pop
				while (dq.front() != check[i])
				{
					dq.push_back(dq.front());
					dq.pop_front();
					ans++;  //�̵� Ƚ��
				}
				//�ش� �����̸� pop
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