#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;


int main()
{
	int n;
	priority_queue <int,vector<int> ,greater<int> >pq;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			int tmp;
			scanf("%d", &tmp);
			pq.push(tmp);
			if (pq.size() > n) pq.pop();
		}
	}
	printf("%d\n", pq.top());
}
