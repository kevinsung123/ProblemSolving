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
	//ȸ���ϴ� ť
	int arr[MAX_N] = { 0, };

	//����Ϸ��� �ڷᱸ�� �� ����
	list<int> L;
	list<int>::iterator iter;
	int ans = 0;

	for (int i = 1; i <= N; i++) L.push_back(i);

	//ã������ ����
	for (int i = 0; i < M; i++)
	{
		int in, l, r;
		int idx = 0;
		cin >> in;
		
		//ù������ �̴� ���
		if (in == L.front()) L.pop_front();
		//2 �Ǵ� 3��° �����ϴ� ���
		else
		{
			for (auto here : L)
			{
				if (here == in) break;
				idx++;
			}
			//2 �Ǵ� 3�� ���� Ƚ��
			l = idx;
			r = L.size() - idx;

			//2��° �����ϴ� ��� �������� ȸ��
			if (l < r)
			{
				// l����ŭ ȸ��
				for (int i = 0; i < l; i++)
				{
					int tmp = L.front();
					L.push_back(tmp);
					L.pop_front();
					ans++;  //2�� ���� Ƚ��
				}

				//�ش� ���ڰ� �� �տ� ����
				L.pop_front();
			}
			else
			{
				//r�� ��ŭ ������ ȸ��
				for (int i = 0; i < r; i++)
				{
					int tmp = L.back();
					L.push_front(tmp);
					L.pop_back();
					ans++;  //3�� ���� Ƚ��
				}
				//�ش� ���� ã���� 
				L.pop_front();
			}

		}
	}
	cout << ans << endl;

}