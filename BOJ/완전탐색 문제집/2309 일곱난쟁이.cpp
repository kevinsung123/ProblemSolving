#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[9];

int main()
{
	for (int i = 0;i < 9;i++) scanf("%d", &arr[i]);
	for (int check = 1;check < (1 << 9);check++)
	{
		int cnt = 0;
		int sum = 0;
		vector<int> match;
		//�� ��쿡���� �� ����
		for (int i = 0;i < 9;i++)
		{
			if (check &(1 << i))
			{
				sum += arr[i];
				match.push_back(arr[i]);
				cnt++;
			}
		}
		if (cnt==7 && sum==100)
		{
			sort(match.begin(), match.end());
			for (int i = 0;i < match.size();i++)printf("%d\n", match[i]);
			break;
		}
	}
}