#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define MAX 9
bool visited[MAX];
int ans[MAX];
set <vector<int>> st;
vector<int> res;
int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<int> perm;
	vector<int> bitmask;
	for (int i = 1;i <= n;i++) perm.push_back(i);
	for (int i = 0;i < m;i++) bitmask.push_back(1);
	for (int i = 0;i < perm.size() - m;i++)bitmask.push_back(0);
	sort(bitmask.begin(), bitmask.end());
	do
	{
		/*for (auto i : perm) cout << i << " ";
		puts(" ");*/
		vector<int> save;
		set<vector<int>>::iterator iter;
		for (int i = 0;i < m;i++) save.push_back(perm[i]);

		//Searches the container for elements equivalent to val and returns the number of matches.
		//Because all elements in a set container are unique, the function can only return 1 (if the element is found) or zero(otherwise).
		if (st.count(save)) continue;  //set���� save�� ���Ұ� � �ִ��� count  1�ƴϸ� 0�� ��ȯ
		st.insert(save); //���Ұ� �����ؾ��Ѵ� insert()�ϸ� key�� ���� ���� 
		iter = st.find(save);
		sv.erase(unique(v.begin(), v.end()), v.end())
		
	
		if (iter != st.end())
		{
			for (int i = 0;i < m;i++)
				cout << save[i] << " ";
			cout << "\n";
		}
	

	} while (next_permutation(perm.begin(), perm.end()));
}


