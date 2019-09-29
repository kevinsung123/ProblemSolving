#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<cstring>
using namespace std;

bool add(unordered_map<int, int> & umap, int data)
{
	//넣으려는 데이터가 없다면 
	if (umap.find(data) == umap.end())
	{
		umap.insert({ data,data });
		return true;
	}

	return false;


}

bool remove (unordered_map<int,int>&umap, int x)
{
	//해당 원소 업으면
	if (umap.find(x) == umap.end())
	{
		
		return false;
	}
	//해당원소가 있으면 true 
	umap.erase(x);
	return true;
}

bool check(unordered_map<int, int> & umap, int x)
{
	//해당원소가 없으면
	if (umap.find(x) == umap.end())
	{
		return false;
	}
	//있으면
    return true;
}

bool toggle(unordered_map<int, int> &umap, int x)
{
	//없으면 추가 연산 
	if (umap.find(x) == umap.end())
	{
		umap.insert({ x,x });
		return true;
	}
	//있으면 false
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