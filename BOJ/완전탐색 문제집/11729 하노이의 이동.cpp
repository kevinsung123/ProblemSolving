#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef struct loc {
	int from;
	int to;
	loc(int from, int to) :from(from), to(to) {};
}Loc;

int n;
int cnt;
vector<Loc> save;

void hanoi(int num, int from, int by, int to)
{
	if (num == 1)
	{
		cnt++;
		//printf("%d %d\n", from, to);
		save.push_back(Loc(from, to));
	}
	else 
	{
		hanoi(num - 1, from, to, by);
		save.push_back(Loc(from, to));
		//printf("%d %d\n", from, to);
		cnt++;
		hanoi(num - 1, by, from, to);
	}
}
int main()
{
	scanf("%d", &n);
	hanoi(n, 1, 2, 3);
	printf("%d\n", cnt);
	for (int i = 0;i < save.size();i++)
	{
		printf("%d %d\n", save[i].from, save[i].to);
	}

}