#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 1000002

int main(void) {

	

	int arr[26] = { 0 };

	int index = 0;
	int same = 0;
	char str[SIZE] = { 0 };
	int max = 0;

	cin.getline(str,SIZE);

	int length = strlen(str);

	for (int i = 0; i < length ; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			int num = str[i] - 'a';
			arr[num]++;
		}
		
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			int num = str[i] - 'A';
			
			arr[num]++;
		}
	}


	/*for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";
	cout << endl;*/

	for (int i = 0; i < 26; i++)
	{
		if (max < arr[i]) {
			max = arr[i];
			index = i;
		}
	}
	
	
	for (int i = 0; i < 26; i++) {
		if (arr[i] == max) {
			same++;
			if (same >= 2)
			{
				printf("?");
				return 0;
			}
		}

	
	}

	
	printf("%c", index + 65);

	return 0;


}