#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> arr;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}

	if (next_permutation(arr.begin(), arr.end()))
	{
		for (auto i : arr) printf("%d ", i);
		printf("\n");
	}
	else puts("-1");
	
}