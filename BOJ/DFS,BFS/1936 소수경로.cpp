#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<queue>
#include<cstring>
using namespace std;
using namespace chrono;
typedef struct _p {
	int num;
	int cnt;
	_p(int num, int cnt) :num(num), cnt(cnt) {};
}P;
const int MAX_N = 10001;
int target;
int start;
vector<bool>isprime;
vector<int> prime;
int check[10001];
int ans;
void bfs()
{
	memset(check, -1, sizeof(check));
	queue<P> Q;
	Q.push(P(start, 0));
	check[start] = 0;
	bool flag = false;
	int level = 0;
	while (1)
	{
		int n_num, n_cnt, c_num, c_cnt, qsize;
		int a[4] = { 0 };
		int b[4] = { 0 };
		int cmp;
		qsize = Q.size();
		if (qsize == 0)
		{
			flag = false;
			break;  //답없으면 
		}
		//printf("level=%d\n", level++);
		for (int i = 0;i < qsize;i++)
		{
			c_num = Q.front().num;
			c_cnt = Q.front().cnt;
			Q.pop();
			//a배열에담는다
			//printf("node num=%d cnt=%d\n", c_num, c_cnt);
			int tmp = c_num;
			for (int m = 3;m >= 0;m--)
			{
				a[m] = tmp % 10;
				tmp /= 10;
			}
			if (c_num == target)
			{
				flag = true;
				ans = c_cnt;
				break;
			}
			//소수배열 차례대로 순회
			for (int k = 0;k < prime.size();k++)
			{
				if (check[prime[k]] != -1) continue;
				n_num = prime[k];
				int cmp = prime[k];

				for (int m = 3;m >= 0;m--)
				{
					b[m] = cmp % 10;
					cmp /= 10;
				}
				//c_cnt 와 cmp 가 한자리만 다를때 넣는다
				int diff = 0;
				for (int n = 0;n < 4;n++)
				{
					if (a[n] != b[n]) diff++;
				}
				if (diff != 1) continue;
				if (diff == 1)
				{
					check[n_num] = check[c_num] + 1;
					Q.push(P(n_num, c_cnt + 1));
				}
			}

		}
		if (flag) break;


	}

	if (flag)printf("%d\n", check[target]);
	else printf("impossible\n");

}



int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		isprime.clear();
		prime.clear();
		ans = 0;
		isprime.resize(MAX_N + 100, 1);  //크기 조심!!
		scanf("%d %d", &start, &target);
		//memset(isprime, 1, sizeof(isprime));
		fill(isprime.begin(), isprime.end(), 1);
		for (int i = 2;i <= MAX_N;i++)
		{
			if (isprime[i])
			{
				for (int p = i * 2;p <= MAX_N;p += i) isprime[p] = false;
			}
			if (isprime[i] && i >1000 && i < 10000) prime.push_back(i);
		}
		bfs();
	/*	system_clock::time_point s = system_clock::now();
		
		system_clock::time_point e = system_clock::now();
		milliseconds milliSec = duration_cast<milliseconds>(e - s);
		cout << milliSec.count() << " us\n";*/
	}

}