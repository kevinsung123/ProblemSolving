#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<cstring>
using namespace std;

bool add(unordered_map<int, int> & umap, int data)
{
	//�������� �����Ͱ� ���ٸ� 
	if (umap.find(data) == umap.end())
	{
		umap.insert({ data,data });
		return true;
	}

	return false;


}

bool remove (unordered_map<int,int>&umap, int x)
{
	//�ش� ���� ������
	if (umap.find(x) == umap.end())
	{
		
		return false;
	}
	//�ش���Ұ� ������ true 
	umap.erase(x);
	return true;
}

bool check(unordered_map<int, int> & umap, int x)
{
	//�ش���Ұ� ������
	if (umap.find(x) == umap.end())
	{
		return false;
	}
	//������
    return true;
}

bool toggle(unordered_map<int, int> &umap, int x)
{
	//������ �߰� ���� 
	if (umap.find(x) == umap.end())
	{
		umap.insert({ x,x });
		return true;
	}
	//������ false
	else
	{
		umap.erase(umap.find(x));
	}
}

bool all(unordered_map<int, int>&umap)
{
	int flag = false;
	for (int i = 1;i <= 20;i++)
	{
		if (umap.find(i) == umap.end())
		{
			flag = true;
			umap.insert({ i,i });
		}
		
	}
	return flag;
}

void empty(unordered_map<int, int>&umap)
{
	umap.clear();

}

int main()
{
	unordered_map<int, int > umap;
	int m;
	cin >> m;

	for (int i = 0;i < m;i++)
	{
		char str[10];
		int num = 0;
		scanf("%s %d", str, &num);
		if (strcmp(str, "add")==0)
		{
			add(umap, num);
			

		}
		else if (strcmp(str, "remove")==0)
		{
			remove(umap, num);
		}
		else if (strcmp(str, "check")==0)
		{
			if (check(umap, num)) cout << "1\n";
			else cout << "0\n";
		}
		else if (strcmp(str, "toggle")==0)
		{
			if (toggle(umap, num));
		}
		else if (strcmp(str, "all")==0)
		{
			all(umap);
		}
		else if (strcmp(str, "empty")==0)
		{
			empty(umap);
		}
	}


}