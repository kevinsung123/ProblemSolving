#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int cache[10][10];

int gcd(int a, int b) //��Ŭ����ȣ����
{
	return b == 0 ? a : gcd(b, a%b);
}

//�м� a/b���� ���ų� ū �ּ��� �ڿ����� ��ȯ�Ѵ�
int ceil(int a, int b)
{
	return ( a + b -1 ) / b;
}

//������ �� �����ǿ� �̹� ���� ����� ���� �־�����, �� ���� ����� ���� ���Ѵ�
vector<int> solve( vector<int> & recipe,  vector<int>& put)
{
	int n = recipe.size();
	//��� recipe[]�� �ִ������� ���Ѵ�
	int b = recipe[0];

	//2�� �̻��� �ִ������� ���ϴ� ��� 
	for (int i = 1; i < n; i++) b = gcd(b, recipe[i]);

	//�ּ��� b/b=1��� ������ �ϹǷ�,  a�� �ʱⰪ�� b�� �д�.
	int a = b;
	
	//X�� ���� ���ϴ� ��ſ� ceil[put[i]*b,recipe[i])�� �ִ밪�� ���Ѵ�
	for (int i = 0; i < n; i++)
		a = max(a, ceil(put[i] * b, recipe[i]));

	//a/b�� �з��� ����� �ȴ�
	vector<int> ret(n);

	for (int i = 0; i < n; i++)
		ret[i] = recipe[i] * a / b - put[i];
	return ret;
}

int main(void)
{
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < 10;i++)
	for (int j = 0; j < 10; j++)
		cout << cache[i][j] << " ";
	cout << endl;
	
	ios::sync_with_stdio(false);
	int c, n, r, p;
	//cin >> c;
	//while (c--)
	//{
	//	vector<int> ans;
	//	vector<int> recipe;
	//	vector<int> put;
	//	cin >> n; //ù�ٿ� ����Ǽ� �Է� ����
	//	for (int i = 0; i < n; i++)
	//	{
	//		cin >> r;
	//		recipe.push_back(r);
	//	}
	//	
	//	for (int i = 0; i < n; i++)   //�̹� ���� ���� ����Ǿ�
	//	{
	//		cin >> p;
	//		put.push_back(p);
	//	}
	//	ans=solve(recipe, put);


	//	for (size_t i = 0; i < ans.size(); i++)
	//		cout << ans[i] << " ";
	//}

}