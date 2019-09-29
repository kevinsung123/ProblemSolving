#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int colMax[3] = { 0 }, colMin[3] = { 0 }, tempMax[3] = { 0 }, tempMin[3] = { 0 };
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		for (int m = 0;m < 3;m++)
		{
			int t = 0;
			scanf("%d", &t);
			tempMax[m] = t;
			tempMin[m] = t;
			//1Àº °øÅë 0=>0,1  2=>2,1
			tempMax[m] += max(colMax[1], m == 1 ? max(colMax[0], colMax[2]):colMax[m]);
			tempMin[m] += min(colMin[1], m == 1 ? min(colMin[0], colMin[2]) : colMin[m]);
		}
		for (int j = 0;j < 3;j++)
		{
			colMax[j] = tempMax[j];
			colMin[j] = tempMin[j];
		}
	}
	sort(colMax, colMax + 3);
	sort(colMin, colMin + 3);
	printf("%d %d\n", colMax[2], colMin[0]);
}